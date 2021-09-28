#include "message.h"
#include <iostream>
#include <limits>
#include <stdio.h>

using namespace std;
namespace duke_xl
{
    std::map<int, send_to_function> message::m_send_to_functions;
    int32_t message::max_handle = 0;
    std::queue<int> message::free_handles;
    std::map<std::string, message_driver *> message::prefix_to_driver;
    std::map<int, message_driver *> message::handle_to_driver;
    std::set<message_driver *> message::all_driver;
    std::set<int> message::all_handles;
    char message::error_msg[256] = "";
    const char *message::p_error_msg = error_msg;

    int message::new_handle()
    {
        return alloc_handle();
    }

    int message::run(int handle, message_driver *driver)
    {
        if (check_driver(handle, driver))
        {
            return -1;
        }

        send_to_function send_to;
        int ret = driver->run(handle, &send_to);
        if (0 != ret)
        {
            return ret;
        }
        handle_to_driver[handle] = driver;

        if (send_to)
        {
            m_send_to_functions[handle] = send_to;
        }
        return 0;
    }

    int message::send_to(int handle, const char *msg, size_t msg_len, std::shared_ptr<message_reply> peer_addr)
    {
        if (msg == nullptr)
        {
            return -1;
            /* code */
        }

        map<int, send_to_function>::iterator iter = m_send_to_functions.find(handle);
        if (iter == m_send_to_functions.end())
        {
            return -1;
        }

        return iter->second(msg, msg_len, peer_addr);
    }

    int message::send_to_wrap(const send_function &send, const char *msg, size_t msg_len, std::shared_ptr<message_reply>, int)
    {
        return send(msg, msg_len);
    }

    int message::send(int handle, const char *msg, size_t msg_len)
    {
        if (msg == nullptr)
            return -1;
        map<int, send_to_function>::iterator iter = m_send_to_functions.find(handle);
        if (iter == m_send_to_functions.end())
        {
            return -1;
        }
        return iter->second(msg, msg_len, std::shared_ptr<message_reply>());
    }

    const char *message::last_error_message()
    {
        return p_error_msg;
    }

    int message::register_driver(message_driver *driver)
    {
        if (driver == nullptr)
        {
            return -1;
        }

        if (prefix_to_driver.find(driver->name()) != prefix_to_driver.end())
        {
            return -1;
        }
        prefix_to_driver[driver->name()] = driver;
        return 0;
    }

    message_driver *message::query_driver(int handle)
    {
        std::map<int, message_driver *>::iterator iter = handle_to_driver.find(handle);
        return iter == handle_to_driver.end() ? nullptr : iter->second;
    }

    int message::check_driver(int handle, message_driver *driver)
    {
        map<string, message_driver *>::iterator iter = prefix_to_driver.find(driver->name());
        if (iter == prefix_to_driver.end())
        {
            std::cout << "Driver not registered";
            return -1;
        }

        if (handle_to_driver.find(handle) != handle_to_driver.end())
        {
            std::cout << "Handle used";
            return -1;
        }

        if (all_driver.find(driver) != all_driver.end())
        {
            std::cout << "Driver used";
            return -1;
        }
        else
        {
            all_driver.insert(driver);
        }
        return 0;
    }

    int message::alloc_handle()
    {
        if (!free_handles.empty()) // 已使用过的handle
        {
            int handle = free_handles.front();
            free_handles.pop();
            all_handles.insert(handle);
            return handle;
        }

        if (max_handle == numeric_limits<int>::max())
        {
            return -1;
        }

        const int ALLOC_BAT_NUM = 10;
        int n = min(ALLOC_BAT_NUM, numeric_limits<int>::max() - max_handle);
        for (int i = 0; i < n; i++)
        {
            free_handles.push(max_handle + 1);
        }
        max_handle += n;
        return alloc_handle();
    }

    void message::dealloc_handle(int handle)
    {
        free_handles.push(handle);
    }

    int message::close(int handle)
    {
        if (all_handles.find(handle) == all_handles.end())
        {
            return -1;
        }

        map<int, message_driver *>::iterator iter = handle_to_driver.find(handle);
        if (iter == handle_to_driver.end())
        {
            all_handles.erase(handle);
            dealloc_handle(handle);
            return 0;
        }

        int ret = iter->second->close();

        m_send_to_functions.erase(handle);

        handle_to_driver.erase(handle);
        all_handles.erase(handle);
        dealloc_handle(handle);
        return 0;
    }

}