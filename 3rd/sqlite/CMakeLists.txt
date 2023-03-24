#需要安装boost库
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../cmake)
message("CMAKE_MODULE_PATH:" ${CMAKE_MODULE_PATH})
find_package(Sqlite3 REQUIRED)
message("SQLITE_ROOT" ${SQLITE_ROOT})
message("SQLITE_LIBRARIES:" ${SQLITE_LIBRARIES})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(sqlite_demo sqlite_demo.cpp)
target_include_directories(sqlite_demo  PUBLIC ${SQLITE_INCLUDE_DIRS})
target_link_libraries(sqlite_demo ${SQLITE_LIBRARIES})