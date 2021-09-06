
find_path(SQLITE_ROOT
        NAMES include/sqlite3.h
        HINTS ../sqlite)

find_path(SQLITE_INCLUDE_DIRS
        NAMES sqlite3.h
        HINTS ${SQLITE_ROOT}/include)

find_library(SQLITE_LIBRARIES
        NAMES libsqlite3.so
        HINTS ${SQLITE_ROOT}/lib)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLITE DEFAULT_MSG
        SQLITE_INCLUDE_DIRS
        SQLITE_LIBRARIES)

mark_as_advanced(
        SQLITE_ROOT
        SQLITE_INCLUDE_DIRS
        SQLITE_LIBRARIES)

if (NOT TARGET SQLITE)
    add_library(SQLITE SHARED IMPORTED)
    set_target_properties(SQLITE PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${SQLITE_INCLUDE_DIRS})
    set_target_properties(SQLITE PROPERTIES IMPORTED_LOCATION ${SQLITE_LIBRARIES})
endif ()

