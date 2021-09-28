/* 
* @Author: duke.xl  
* @Brief: duke.xl  
* @Date: 2021-09-23 14:07:39  
 * @Last Modified by: duke.xl
 * @Last Modified time: 2021-09-23 14:16:51
*/

#ifndef _MESSAGE_DIVER_H_
#define _MESSAGE_DIVER_H_

#include <stdint.h>
#include <string.h>
#include <string>
#include <functional>
#include <memory>

namespace duke_xl
{
    class message_reply
    {
    public:
        message_reply() {}
        virtual ~message_reply() {}
    };

    typedef std::function<int(const char *msg, size_t msg_len)> send_function;
    typedef std::function<int(const char *msg, size_t msg_len, std::shared_ptr<message_reply>)> send_to_function;
    typedef std::function<int(int, const char *, size_t msg_len, std::shared_ptr<message_reply>)> on_message;

    class message_driver // 网络驱动统一接口
    {
    public:
        enum DRIVER_TYPE
        {
            MESSAGE_CLIENT,
            MESSAGE_SERVER
        };

        virtual ~message_driver() {}
        virtual int init(DRIVER_TYPE type) = 0;
        virtual int run(int handle, send_to_function *send_to) = 0;

        virtual int close() = 0;
        virtual std::string name() = 0;
        void set_on_message(const on_message &on_message)
        {
            m_on_message = on_message;
        }

    protected:
        on_message m_on_message;
    };
}

#endif