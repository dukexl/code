find_library(UTILITY_LIB NAMES utility PATHS "${PROJECT_BINARY_DIR}/lib/")

add_executable(l_124_bin_tree_max_path_sum l_124_bin_tree_max_path_sum.cpp)
target_link_libraries(l_124_bin_tree_max_path_sum ${UTILITY_LIB})