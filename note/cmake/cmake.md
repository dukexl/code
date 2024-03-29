Cmake 
第一：简介
cmake是一个跨平台,开源的构建系统。它是一个集软件构建、测试、打包于一身的软件。它使用与平台和编译器独立的配置文件来对软件编译过程进行控制.

第二：常用命令
1.指定cmake的最小版本
cmake_minimum_required(VERSION 3.17)  每个工程构建都需要一个最低版本

2.设置项目名称
project(project_name)  每个工程都需要一个工程名
可以查看 PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR的值

3.设置编译类型
add_executable(project_name project_name.cpp) #可执行文件
add_library(common STATIC util.cpp) # 生成静态库文件
add_library(common SHARED util.cpp) # 生成动态库或共享库
默认名称linux下 project_name libcommon.a libcommon.so 
        windows 下：project_name.exe common.lib common.dll
		
4.指定编译包含的源文件
add_library(project_name project_name.cpp util.cpp xxx.cpp)
4.1 可以搜索所有的cpp
aux_source_directory(dir VAR) 发现dir目录下*.cpp，并赋值给VAR
eg:aux_source_directory(. SRC_LIST)  add_library(project_name ${SRC_LIST})
4.2 自定义搜索规则
file(GLOB SRC_LIST "*.cpp" "protocol/*.cpp")
或者
file(GLOB SRC_LIST "*.cpp)
file(GLOB SRC_PROTOCOL_LIST "protocol/*.cpp")
或者
aux_source_directory(. SRC_LIST)
aux_source_directory(protocol SRC_PROTOCOL_LIST)

5.查找指定的库文件
find_library(VAR name path)
find_library(log-lib log)
find_file(),find_path(),find_program(),find_package()

6.设置包含的目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
                    ${CMAKE_CURRENT_SOURCE_DIR}/include)
或者：
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR}")

7.设置链接库搜索目录
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs})
或者
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/libs")

8.设置target需要链接的库
target_link_libraries(目标库  目标库需要链接的库)
在windows下，系统会根据链接库目录，搜索xxx.lib 
linux下会搜索xxx.so或者xxx.a，会优先搜索xxx.so
8.1 指定链接动态库或静态库
target_link_libraries(demo libxxx.a)
target_link_libraries(demo libxxx.so)
8.2 指定全路径
target_link_libraries(demo ${CMAKE_CURRENT_SOURCE_DIR}/libs/libxxx.a)
target_link_libraries(demo ${CMAKE_CURRENT_SOURCE_DIR}/libs/libxxx.so)
8.3 指定多个连接库
target_link_libraries(demo ${CMAKE_CURRENT_SOURCE_DIR}/libs/libxxx.a pthread)

9.设置变量
9.1 直接set
set(CLIENT_SRCS src/main.cpp)  设置变量名，后面可以${CLIENT_SRCS} 表示main.cpp
add_executable(project_name CLIENT_SRCS) 生成project_name
9.2 追加
set(CLIENT_SRCS src/main.cpp)
set(CLIENT_SRCS ${CLIENT_SRCS} src/test.cpp)
9.3 list追加或删除
set(CLIENT_SRCS src/main.cpp)
list(APPEND CLIENT_SRCS test.cpp)
list(REMOVE_ITEM CLIENT_SRCS test.cpp)

10.条件控制
10.1 if…elseif…else…endif

逻辑判断和比较：
if (expression)：expression 不为空（0,N,NO,OFF,FALSE,NOTFOUND）时为真
if (not exp)：与上面相反
if (var1 AND var2)
if (var1 OR var2)
if (COMMAND cmd)：如果 cmd 确实是命令并可调用为真
if (EXISTS dir) if (EXISTS file)：如果目录或文件存在为真
if (file1 IS_NEWER_THAN file2)：当 file1 比 file2 新，或 file1/file2 中有一个不存在时为真，文件名需使用全路径
if (IS_DIRECTORY dir)：当 dir 是目录时为真
if (DEFINED var)：如果变量被定义为真
if (var MATCHES regex)：给定的变量或者字符串能够匹配正则表达式 regex 时为真，此处 var 可以用 var 名，也可以用 ${var}
if (string MATCHES regex)

数字比较：
if (variable LESS number)：LESS 小于
if (string LESS number)
if (variable GREATER number)：GREATER 大于
if (string GREATER number)
if (variable EQUAL number)：EQUAL 等于
if (string EQUAL number)

字母表顺序比较：
if (variable STRLESS string)
if (string STRLESS string)
if (variable STRGREATER string)
if (string STRGREATER string)
if (variable STREQUAL string)
if (string STREQUAL string)

if(MSVC)
    set(LINK_LIBS common)
else()
    set(boost_thread boost_log.a boost_system.a)
endif()

target_link_libraries(demo ${LINK_LIBS})
# 或者
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fpermissive -g")
else()
    add_definitions(-D_SCL_SECURE_NO_WARNINGS
    D_CRT_SECURE_NO_WARNINGS
    -D_WIN32_WINNT=0x601
    -D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif()
 
if(${CMAKE_BUILD_TYPE} MATCHES "debug")
    ...
else()
    ...
endif()

10.2 while…endwhile
while(condition)
    ...
endwhile()

10.3 foreach…endforeach
foreach(loop_var RANGE start stop [step])
    ...
endforeach(loop_var)
start 表示起始数，stop 表示终止数，step 表示步长，示例
foreach(i RANGE 1 9 2)
    message(${i})
endforeach(i)
# 输出：13579

11.打印信息
message(${PROJECT_SOURCE_DIR})
message("build with debug mode")
message(WARNING "this is warnning message")
message(FATAL_ERROR "this build has many error") # FATAL_ERROR 会导致编译失败

12.包含其他cmake文件
include(./common.cmake) # 指定包含文件的全路径
include(def) # 在搜索路径中搜索def.cmake文件
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake) # 设置include的搜索路径

13.常用变量
13.1 预定义变量
PROJECT_SOURCE_DIR：工程的根目录
PROJECT_BINARY_DIR：运行 cmake 命令的目录，通常是 ${PROJECT_SOURCE_DIR}/build
PROJECT_NAME：返回通过 project 命令定义的项目名称
CMAKE_CURRENT_SOURCE_DIR：当前处理的 CMakeLists.txt 所在的路径
CMAKE_CURRENT_BINARY_DIR：target 编译目录
CMAKE_CURRENT_LIST_DIR：CMakeLists.txt 的完整路径
CMAKE_CURRENT_LIST_LINE：当前所在的行
CMAKE_MODULE_PATH：定义自己的 cmake 模块所在的路径，SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)，然后可以用INCLUDE命令来调用自己的模块
EXECUTABLE_OUTPUT_PATH：重新定义目标二进制可执行文件的存放位置
LIBRARY_OUTPUT_PATH：重新定义目标链接库文件的存放位置

13.2 环境变量 $ENV{Name}
set(ENV{Name} value) # 这里没有“$”符号

13.3 系统信息
CMAKE_MAJOR_VERSION：cmake 主版本号，比如 3.4.1 中的 3
­CMAKE_MINOR_VERSION：cmake 次版本号，比如 3.4.1 中的 4
­CMAKE_PATCH_VERSION：cmake 补丁等级，比如 3.4.1 中的 1
­CMAKE_SYSTEM：系统名称，比如 Linux-­2.6.22
­CMAKE_SYSTEM_NAME：不包含版本的系统名，比如 Linux
­CMAKE_SYSTEM_VERSION：系统版本，比如 2.6.22
­CMAKE_SYSTEM_PROCESSOR：处理器名称，比如 i686
­UNIX：在所有的类 UNIX 平台下该值为 TRUE，包括 OS X 和 cygwin
­WIN32：在所有的 win32 平台下该值为 TRUE，包括 cygwin

13.4 主要开关选项
BUILD_SHARED_LIBS：这个开关用来控制默认的库编译方式，如果不进行设置，使用 add_library 又没有指定库类型的情况下，默认编译生成的库都是静态库。如果 set(BUILD_SHARED_LIBS ON) 后，默认生成的为动态库
CMAKE_C_FLAGS：设置 C 编译选项，也可以通过指令 add_definitions() 添加
CMAKE_CXX_FLAGS：设置 C++ 编译选项，也可以通过指令 add_definitions() 
add_definitions(-DENABLE_DEBUG -DABC) # 参数之间用空格分隔

例子



14.头文件
14.1 target_include_directories(client PRIVATE include) 加头文件
include_directories(./include) 增加头文件目录

14.2 add_library(<name> [STATIC | SHARED | MODULE]
            [EXCLUDE_FROM_ALL]
            [source1] [source2] [...])  指定的源文件生成链接文件
  target_link_libraries(<target> [item1] [item2] [...]
                      [[debug|optimized|general] <item>] ...)
  eg:target_link_libraries(client PRIVATE common) 目标文件与库文件进行连接
  link_directories(lib)  eg:link_directories(./lib) 添加lib文件目录

14.3 add_subdirectory(tests) 增加测试

14.4 include(CTest)  用来载入并运行来自于文件或模块的CMake代码

14.5 c++ 标准版本
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_STANDARD 14)

14.6 add_test
add_test(NAME craft_test COMMAND craft --gtest_output='xml:report.xml')