# 设置变量
set(LIBNET_SRC myBinTree.cpp) 

# 包含头文件
include_directories(../)


# 生成动态库和静态库
add_library(utility_dynamic SHARED ${LIBNET_SRC}) 
add_library(utility_static STATIC ${LIBNET_SRC}) 

# 生成网络库
set_target_properties(utility_dynamic PROPERTIES OUTPUT_NAME "utility")
#set_target_properties(utility_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)
set_target_properties(utility_static PROPERTIES OUTPUT_NAME "utility")

