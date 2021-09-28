/* 
* @Author: duke.xl  
* @Brief: duke.xl  
* @Date: 2021-09-23 14:18:27  
 * @Last Modified by: duke.xl
 * @Last Modified time: 2021-09-23 14:30:33
*/

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "message_driver.h"
#include <map>
#include <set>
#include <queue>

namespace duke_xl
{
    class message
    {
    public:
        // 创建一个句柄
        static int new_handle();
        // 启动客户端模式（消费者）
        static int run(int handle, message_driver *driver);
        // 服务端发送消息
        static int send_to(int handle, const char *msg, size_t msg_len, std::shared_ptr<message_reply> peer_addr);
        // 客户端发送消息
        static int send(int handle, const char *msg, size_t msg_len);
        // 关闭句柄
        static int close(int handle);

        // error msg
        static char error_msg[256];
        static const char *p_error_msg;
        // 返回错误消息
        static const char *last_error_message();
        // 注册通信协议驱动
        static int register_driver(message_driver *driver);
        // 查询通信协议驱动
        static message_driver *query_driver(int handle);

    private:
        static int check_driver(int handle, message_driver *driver);
        static std::map<int, send_to_function> m_send_to_functions;
        static int32_t max_handle;
        static std::queue<int> free_handles;
        static std::map<std::string, message_driver *> prefix_to_driver;
        static std::map<int, message_driver *> handle_to_driver;
        static std::set<message_driver *> all_driver;
        static std::set<int> all_handles;

    private:
        static int alloc_handle();
        static void dealloc_handle(int handle);
        static int send_to_wrap(const send_function &send, const char *msg, size_t msg_len, std::shared_ptr<message_reply> peer_addr, int flag);
    };
}

#endif