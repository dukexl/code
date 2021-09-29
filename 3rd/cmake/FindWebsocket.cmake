find_path(WEBSOCKET_ROOT
        NAMES include/websocketpp/config/asio_no_tls.hpp
        HINTS $ENV{WEBSOCKET_HOME})

find_path(WEBSOCKET_INCLUDE_DIRS
        NAMES websocketpp/config/asio_no_tls.hpp
        HINTS ${WEBSOCKET_ROOT}/include)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WEBSOCKET DEFAULT_MSG
        WEBSOCKET_INCLUDE_DIRS)

mark_as_advanced(
        WEBSOCKET_ROOT
        WEBSOCKET_INCLUDE_DIRS)

if (NOT TARGET Websocket)
    add_library(Websocket INTERFACE IMPORTED)
    set_target_properties(Websocket PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${WEBSOCKET_INCLUDE_DIRS})
endif ()
