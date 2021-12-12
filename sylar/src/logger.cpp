/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2021-12-02 20:59:15
 * @LastEditors: xuli
 * @LastEditTime: 2021-12-09 22:02:27
 */
#include "logger.h"
#include <map>
#include <iostream>
#include <functional>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

namespace sylar
{
    /************************** LogLevel class begin *******************/
    const char *LogLevel::ToString(LogLevel::Level level)
    {
        switch (level)
        {
#define XX(name)         \
    case LogLevel::name: \
        return #name;    \
        break;
            XX(DEBUG);
            XX(INFO);
            XX(WARN);
            XX(ERROR);
            XX(FATAL);
#undef XX

        default:
            return "UNKNOW";
        }
        return "UNKNOW";
    }

    LogLevel::Level LogLevel::FromString(const std::string &str)
    {
#define XX(level, v)            \
    if (str == #v)              \
    {                           \
        return LogLevel::level; \
    }
        XX(DEBUG, debug);
        XX(INFO, info);
        XX(WARN, warn);
        XX(ERROR, error);
        XX(FATAL, fatal);

        XX(DEBUG, DEBUG);
        XX(INFO, INFO);
        XX(WARN, WARN);
        XX(ERROR, ERROR);
        XX(FATAL, FATAL);
        return LogLevel::UNKNOW;
#undef XX
    }

    /************************** LogLevel class end *******************/

    /************************** LogEvent class begin *******************/
    LogEvent::LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level,
                       const char *file, int32_t line, uint32_t elapse,
                       uint32_t thread_id, uint32_t fiber_id, uint64_t time, const std::string &thread_name)
        : m_file(file), m_line(line), m_elapse(elapse), m_threadId(thread_id), m_fiberId(fiber_id),
          m_time(time), m_threadName(thread_name), m_logger(logger), m_level(level) {}

    void LogEvent::format(const char *fmt, ...)
    {
        va_list al;
        va_start(al, fmt);
        format(fmt, al);
        va_end(al);
    }

    void LogEvent::format(const char *fmt, va_list al)
    {
        char *buf = nullptr;
        int len = vasprintf(&buf, fmt, al);
        if (len != -1)
        {
            m_ss << std::string(buf, len);
            free(buf);
        }
    }

    /************************** LogEvent class end *******************/

    /************************** LogEventWrap class begin *******************/
    LogEventWrap::LogEventWrap(LogEvent::ptr e) : m_event(e) {}
    LogEventWrap::~LogEventWrap()
    {
        m_event->getLogger()->log(m_event->getLevel(), m_event);
    }

    std::stringstream &LogEventWrap::getSS()
    {
        return m_event->getSS();
    }
    /************************** LogEventWrap class end *******************/

    /************************** LogFormatter class begin *******************/
    LogFormatter::LogFormatter(const std::string &pattern) : m_pattern(pattern)
    {
        init();
    }

    std::string LogFormatter::format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)
    {
        std::stringstream ss;
        for (auto &i : m_items)
        {
            i->format(ss, logger, level, event);
        }
        return ss.str();
    }

    std::ostream &LogFormatter::format(std::ostream &ofs, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event)
    {
        for (auto &i : m_items)
        {
            i->format(ofs, logger, level, event);
        }
        return ofs;
    }

    void LogFormatter::init()
    {
        std::vector<std::string, std::string, int> > vec;
        std::string nstr;
        for (size_t i = 0; i < m_pattern.size(); ++i)
        {
            if (m_pattern[i] != '%')
            {
                nstr.append(1,m_pattern[i]);
            }
        }
    }
}

/************************** LogFormatter class end *******************/

/************************** LogEventWrap class begin *******************/
/************************** LogEventWrap class end *******************/

Logger::Logger(const std::string &name) : m_name(name)
{
}

void Logger::log(LogLevel::Level level, const LogEvent::ptr &event)
{
    if (level >= m_level)
    {
        for (auto &i : m_appenders)
        {
            i->log(level, event);
        }
    }
}

void Logger::debug(LogEvent::ptr event)
{
    log(LogLevel::DEBUG, event);
}
void Logger::info(LogEvent::ptr event) { log(LogLevel::INFO, event); }
void Logger::warn(LogEvent::ptr event) { log(LogLevel::WARN, event); }
void Logger::error(LogEvent::ptr event) { log(LogLevel::ERROR, event); }
void Logger::fatal(LogEvent::ptr event) { log(LogLevel::FATAL, event); }

void Logger::addAppender(LogAppender::ptr appender)
{
    m_appenders.push_back(appender);
}
void Logger::delAppender(LogAppender::ptr appender)
{
    for (auto it = m_appenders.begin(); it != m_appenders.end(); it++)
    {
        if (*it == appender)
        {
            m_appenders.erase(it);
            break;
        }
    }
}

void StdoutLogAppender::log(LogLevel::Level level, LogEvent::ptr event)
{
}

FileLogAppender::FileLogAppender(const std::string &filename)
{
}
void FileLogAppender::log(LogLevel::Level level, LogEvent::ptr event)
{
}
}