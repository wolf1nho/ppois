cmake_minimum_required(VERSION 3.16)
project(Vector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(ENABLE_COVERAGE "Enable coverage reporting (requires gcovr)" OFF)

if(ENABLE_COVERAGE)
    message(STATUS "Coverage instrumentation enabled")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

add_library(Vector STATIC
    Vector.cpp
)

target_include_directories(Vector PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(MenuTest tests/MenuVector.cpp)
target_link_libraries(MenuTest Vector)
add_executable(VectorTests tests/VectorTest.cpp)
target_link_libraries(VectorTests Vector gtest gtest_main Threads::Threads)

add_test(NAME VectorTests COMMAND VectorTests)


add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS VectorTests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests with CTest"
)


if(ENABLE_COVERAGE)
    find_program(GCOVR_PATH gcovr)

    if(NOT GCOVR_PATH)
        message(WARNING "gcovr not found. Install via: pip install gcovr")
    else()
        add_custom_target(coverage
            COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
            COMMAND ${GCOVR_PATH} -r ${CMAKE_SOURCE_DIR} --html --html-details -o ${CMAKE_BINARY_DIR}/coverage.html --exclude-directories ${CMAKE_BINARY_DIR}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            DEPENDS VectorTests
            COMMENT "Generating coverage report with gcovr..."
        )
    endif()
endif()
