/*
 * @Descripttion: your project
 * @version: 1.0
 * @Author: xuli
 * @Date: 2021-12-05 19:49:30
 * @LastEditors: xuli
 * @LastEditTime: 2021-12-08 22:26:44
 */
#include "logger.h"
#include <iostream>
using namespace sylar;

int main()
{
    std::cout << LogLevel::ToString(LogLevel::INFO) << std::endl;
    std::cout << LogLevel::FromString("debug") << std::endl;

    std::shared_ptr<Logger> logger = std::make_shared<Logger>();

    LogEvent tmpLogEvent(logger, LogLevel::INFO, "ni", 0, 0, 0, 0, 0, "tmp");
    tmpLogEvent.format("nihao", " hello", " world");
    std::cout << tmpLogEvent.getContent() << std::endl; // nihao
    return 0;
}