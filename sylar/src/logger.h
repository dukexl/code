#ifndef _SYLAR_LOGGER_H_
#define _SYLAR_LOGGER_H_

#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

namespace sylar
{
    class Logger;
    class LoggerManager;

    // 日志级别
    class LogLevel
    {
    public:
        enum Level
        {
            UNKNOW = 0,
            DEBUG = 1,
            INFO = 2,
            WARN = 3,
            ERROR = 4,
            FATAL = 5
        };

        // 将日志级别转换成文本输出
        static const char *ToString(LogLevel::Level level);
        // 将文本转换为日志级别
        static LogLevel::Level FromString(const std::string &str);
    };

    // 日志事件
    class LogEvent
    {
    public:
        typedef std::shared_ptr<LogEvent> ptr;
        LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level,
                 const char *file, int32_t line, uint32_t elapse,
                 uint32_t thread_id, uint32_t fiber_id, uint64_t time,
                 const std::string &thread_name);

        const char *getFile() const { return m_file; }
        int32_t getLine() const { return m_line; }
        uint32_t getElapse() const { return m_elapse; }
        uint32_t getThreadId() const { return m_threadId; }
        uint32_t getFiberId() const { return m_fiberId; }
        uint64_t getTime() const { return m_time; }
        const std::string getContent() const { return m_ss.str(); }
        std::shared_ptr<Logger> getLogger() const { return m_logger; }
        LogLevel::Level getLevel() const { return m_level; }
        std::stringstream &getSS() { return m_ss; }
        void format(const char *fmt, ...);
        void format(const char *fmt, va_list al);

    private:
        const char *m_file = nullptr;     // 文件名
        uint32_t m_line = 0;              // 行号
        uint32_t m_elapse = 0;            // 程序启动开始到现在的毫秒数
        uint32_t m_threadId = 0;          // 线程id
        uint32_t m_fiberId = 0;           // 协程id
        uint32_t m_time;                  // 时间戳
        std::string m_threadName;         // 线程名称
        std::stringstream m_ss;           // 日志内容流
        std::shared_ptr<Logger> m_logger; // 日志器
        LogLevel::Level m_level;
    };

    // 日志事件包装器
    class LogEventWrap
    {
    public:
        LogEventWrap(LogEvent::ptr e);
        ~LogEventWrap();
        LogEvent::ptr getEvent() const { return m_event; }
        std::stringstream &getSS();

    private:
        LogEvent::ptr m_event;
    };

    // 日志格式器
    class LogFormatter
    {
    public: // 默认格式 "%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"
        typedef std::shared_ptr<LogFormatter> ptr;

        LogFormatter(const std::string &pattern);
        std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
        std::ostream &format(std::ostream &ofs, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);

        class FormatItem
        {
        public:
            typedef std::shared_ptr<FormatItem> ptr;
            virtual ~FormatItem() {}
            virtual void format(std::ostream &os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
        };
        void init();
        bool isError() const { return m_error; }
        const std::string getPattern() const { return m_pattern; }

    private:
        std::string m_pattern;                // 日志格式模板
        std::vector<FormatItem::ptr> m_items; // 日志格式解析后格式
        bool m_error = false;                 // 是否有错
    };

    // 日志输出地
    class LogAppender
    {
    public:
        typedef std::shared_ptr<LogAppender> ptr;
        virtual ~LogAppender() {}

        virtual void log(LogLevel::Level level, LogEvent::ptr event) = 0;

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