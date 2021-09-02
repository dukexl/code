#需要安装boost库

find_package(Boost REQUIRED COMPONENTS filesystem system program_options )
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)

message("Boost_INCLUDE_DIR:" ${Boost_INCLUDE_DIR})
message("Boost_LIBRARY_DIRS:" ${Boost_LIBRARY_DIRS})
message("Boost_LIBRARIES:" ${Boost_LIBRARIES})
add_executable(boost_vision boost_vision.cpp)
target_link_libraries(boost_vision Boost::filesystem Boost::system Boost::program_options pthread)


# find_package(Boost)

# if(BOOST_FOUND)
#   add_executable(boost_vision boost_vision.cpp)
#   include_directories(${BOOST_INCLUDE_DIR})
#   target_link_libraries(boost_vision ${BOOST_LIBRARY})
# else(BOOST_FOUND)
#   message(FATAL_ERROR "Boost library not found")
# endif(BOOST_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)