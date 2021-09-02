message("start")
find_path(BOOST_INCLUDE version.hpp /opt/boost_1_64_0/include/boost-1_64/boost/)
find_library(BOOST_LIBRARY NAMES boost_filesystem-gcc48-mt-1_64 PATH /opt/boost_1_64_0/lib/)
set(BOOST_INCLUDE_DIR ${BOOST_INCLUDE}/../)

message("BOOST_INCLUDE:" ${BOOST_INCLUDE})
message("BOOST_INCLUDE_DIR:" ${BOOST_INCLUDE_DIR})
message("BOOST_LIBRARY:" ${BOOST_LIBRARY})


if(BOOST_INCLUDE_DIR AND BOOST_LIBRARY)
  SET(BOOST_FOUND true)
endif(BOOST_INCLUDE_DIR AND BOOST_LIBRARY)

if(BOOST_FOUND)
  if(NOT BOOST_FIND_QUIETLY)
    message(STATUS "Found BOOST: ${BOOST_INCLUDE_DIR} ${BOOST_LIBRARY}")
  endif(NOT BOOST_FIND_QUIETLY)
else(BOOST_FOUND)
  if(BOOST_FIND_REQUIRED)
    message(FATAL_ERROR "Could not find boost library")
  endif(BOOST_FIND_REQUIRED)
endif(BOOST_FOUND)
