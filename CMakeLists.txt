# Get the task name from the current directory
get_filename_component(task ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required(VERSION 3.5.1)

# Name the project after the task
project(${task} CXX)

# Get a source filename from the task name by replacing -'s with _'s
string(REPLACE "-" "_" file ${task})

# Implementation could be only a header
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
    set(task_cpp ${file}.cpp)
else()
    set(task_cpp "")
endif()

# Use the common Catch library?
#if(EXERCISM_COMMON_CATCH)
    # For Exercism track development only
    #add_executable(${task} ${file}_test.cpp ${task_cpp} ${file}.h $<TARGET_OBJECTS:catchlib>)
    #else()
# Build executable from sources and headers
add_executable(${task} ${file}_test.cpp ${task_cpp} ${file}.h test/tests-main.cpp)
    #endif()

set_target_properties(${task} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED OFF
    CXX_EXTENSIONS OFF
)

set(CMAKE_BUILD_TYPE Debug)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set_target_properties(${task} PROPERTIES
        COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror"
    )
endif()

# Configure to run all the tests?
if(${EXERCISM_RUN_ALL_TESTS})
    target_compile_definitions(${task} PRIVATE EXERCISM_RUN_ALL_TESTS)
endif()

# Tell MSVC not to warn us about unchecked iterators in debug builds
if(${MSVC})
    set_target_properties(${task} PROPERTIES
        COMPILE_DEFINITIONS_DEBUG _SCL_SECURE_NO_WARNINGS)
endif()

# Run the tests on every build
add_custom_target(test_${task} ALL DEPENDS ${task} COMMAND ${task})
