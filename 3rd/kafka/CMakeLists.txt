include_directories(./include/)
find_library(KAFKA NAMES rdkafka++ PATHS "./lib/")
message("kafka:" ${KAFKA})

add_executable(kafka kafkaproducer.cpp)
target_link_libraries(kafka ${KAFKA})
