#需要安装boost库
add_executable(ctrip_test ctrip_thread_pool.cpp test.cpp)

target_link_libraries(ctrip_test pthread)