cmake_minimum_required(VERSION 3.0) 
###################################################################################
project(code)

# if (CMAKE_BUILD_TYPE) 
# else() 
# 	set(CMAKE_BUILD_TYPE RELEASE) 
# endif()

set(CMAKE_BUILD_TYPE debug) 
set(CXX_FLAGS
    -g
    -DVALGRIND
    -DCHECK_PTHREAD_RETURN_VALUE
    -D_FILE_OFFSET_BITS=64
    -Wall
    -Wextra
    -Wno-reorder
    # -Werror
    -Wno-conversion
    -Wno-unused-parameter
    -Wno-sign-compare
    # -Wold-style-cast
    -Woverloaded-virtual
    -Wno-shadow
    -Wpointer-arith
    # -Wshadow
    -Wno-write-strings
    -Wno-format
    -march=native
    -std=c++11
    -rdynamic ) 
	
if(CMAKE_BUILD_BITS EQUAL 32) 
	list(APPEND CXX_FLAGS "-m32") 
endif() 

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++") 
set(CMAKE_CXX_FLAGS_DEBUG "-O0") 
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG") 
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) 
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

message("------------ Options -------------") 
message("  CMAKE_PROJECT: ${PROJECT_NAME}") 
message("  CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message("  CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}") 
message("  CMAKE_BUILD_BITS: ${CMAKE_BUILD_BITS}") 
message("  CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}") 
message("  EXECUTABLE_OUTPUT_PATH: ${EXECUTABLE_OUTPUT_PATH}")
message("  LIBRARY_OUTPUT_PATH: ${LIBRARY_OUTPUT_PATH}") 

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})


add_subdirectory(3rd)
add_subdirectory(algorithm) 
# add_subdirectory(base) 
# add_subdirectory(designpatterns)

# add_subdirectory(sylar)
