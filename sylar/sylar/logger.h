#ifndef _SYLAR_LOGGER_H_
#define _SYLAR_LOGGER_H_

#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <stringstream>
#include <fstream>

namespace sylar
{
    // 日志事件
    class LogEvent
    {
    public:
        typedef std::shared_ptr<LogEvent> ptr;
        LogEvent();

    private:
        const char *m_file = nullptr; // 文件名
        uint32_t m_line = 0;          // 行号
        uint32_t m_elapse = 0;        // 程序启动开始到现在的毫秒数
        uint32_t m_threadId = 0;      // 线程id
        uint32_t m_fiberId = 0;       // 携程id
        uint32_t m_time;              // 时间戳
        std::string m_content;
    };

    // 日志级别
    class LogLevel
    {
    public:
        enum Level
        {
            DEBUG = 1,
            INFO = 2,
            WARN = 3,
            ERROR = 4,
            FATAL = 5
        };
    };

    // 日志格式器
    class LogFormatter
    {
    public:
        typedef std::shared_ptr<LogFormatter> ptr;
        std::string format(LogEvent::ptr event);

    private:
    };

    // 日志输出地
    class LogAppender
    {
    public:
        typedef std::shared_ptr<LogAppender> ptr;
        virtual ~LogAppender() {}

        virtual void log(LogLevel::Level level, LogEvent::ptr event) = 0 ;

    private:
        LogLevel::Level m_level;
    };

    // 日志器
    class Logger
    {
    public:
        typedef std::shared_ptr<Logger> ptr;
        Logger(const std::string &name = "root");
        void log(LogLevel::Level level, const LogEvent::ptr &event);

        void debug(LogEvent::ptr event);
        void info(LogEvent::ptr event);
        void warn(LogEvent::ptr event);
        void error(LogEvent::ptr event);
        void fatal(LogEvent::ptr event);

        void addAppender(LogAppender::ptr appender);
        void delAppender(LogAppender::ptr appender);
        LogLevel::Level getLevel() { return m_level; }
        void setLevel(const LogLevel::Level &level) { m_level = level; }

    private:
        std::string m_name;                      // 日志名称
        LogLevel::Level m_level;                 // 日志级别
        std::list<LogAppender::ptr> m_appenders; // appender 集合
    };

    class StdoutLogAppender : public LogAppender
    {
        public:
        typedef std::shared_ptr<StdoutLogAppender> ptr;
        virtual void log(LogLevel::Level level, LogEvent::ptr event) override;
    };
    class FileLogAppender : public LogAppender
    {
         public:
        typedef std::shared_ptr<FileLogAppender> ptr;
        FileLogAppender(const std::string &filename);
        virtual void log(LogLevel::Level level, LogEvent::ptr event) override;

        private:
        std::string m_name;
        std::ofstream m_filestream;
    };
}

#endif