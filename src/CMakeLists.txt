set(REGEX_INCLUDE_FILE ${CMAKE_CURRENT_BINARY_DIR}/regex.inc)
add_custom_command(OUTPUT ${REGEX_INCLUDE_FILE} COMMAND xxd -i regex.impala > ${REGEX_INCLUDE_FILE} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_source_files_properties(${REGEX_INCLUDE_FILE} PROPERTIES GENERATED TRUE)

add_executable(regex main.cpp ${REGEX_INCLUDE_FILE})
target_include_directories(regex PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${AnyDSL_runtime_INCLUDE_DIRS})
target_link_libraries(regex ${AnyDSL_runtime_LIBRARIES})
