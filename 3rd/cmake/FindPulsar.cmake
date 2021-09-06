
find_path(PULSAR_ROOT
        NAMES include/pulsar/Client.h
        HINTS $ENV{PULSAR_HOME})

find_path(PULSAR_INCLUDE_DIRS
        NAMES pulsar/Client.h
        HINTS ${PULSAR_ROOT}/include)

find_library(PULSAR_LIBRARIES
        NAMES libpulsar.so.2.7.0
        HINTS ${PULSAR_ROOT}/lib)

find_library(PULSAR_LIBRARIES1
        NAMES libpulsar.so
        HINTS ${PULSAR_ROOT}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Pulsar DEFAULT_MSG
        PULSAR_INCLUDE_DIRS
        PULSAR_LIBRARIES
        PULSAR_LIBRARIES1)

mark_as_advanced(
        PULSAR_ROOT
        PULSAR_INCLUDE_DIRS
        PULSAR_LIBRARIES
        PULSAR_LIBRARIES1)

if (NOT TARGET Pulsar)
    add_library(Pulsar SHARED IMPORTED)
    set_target_properties(Pulsar PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${PULSAR_INCLUDE_DIRS})
    set_target_properties(Pulsar PROPERTIES IMPORTED_LOCATION ${PULSAR_LIBRARIES})
    set_target_properties(Pulsar PROPERTIES IMPORTED_LOCATION ${PULSAR_LIBRARIES1})
endif ()

