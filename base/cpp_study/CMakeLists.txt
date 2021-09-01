# 设置C++ 标准
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# 生成可执行文件
add_executable(version version.cpp)
add_executable(sort sort.cpp)
