find_library(UTILITY_LIB NAMES utility PATHS "${PROJECT_BINARY_DIR}/lib/")

add_executable(l_124_bin_tree_max_path_sum l_124_bin_tree_max_path_sum.cpp)
#这里可能会有错误，需要先编译好so文件
target_link_libraries(l_124_bin_tree_max_path_sum ${UTILITY_LIB})