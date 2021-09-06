#需要安装boost库
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../cmake)
message("CMAKE_MODULE_PATH:" ${CMAKE_MODULE_PATH})
find_package(Pulsar REQUIRED)
message("PULSAR_ROOT" ${PULSAR_ROOT})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(pulsar_test pulsar.cpp)
target_link_libraries(pulsar_test Pulsar )