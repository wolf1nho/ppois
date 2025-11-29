cmake_minimum_required(VERSION 3.10.0)
project(SortMethods VERSION 0.1.0 LANGUAGES C CXX)

option(ENABLE_COVERAGE "Enable coverage reporting (requires gcovr)" ON)

if(ENABLE_COVERAGE)
    message(STATUS "Coverage instrumentation enabled")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

add_library(SortMethods STATIC CombSort.h TournamentSort.h)

target_include_directories(SortMethods PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(SortMethodsTest main.cpp CombSortTest.cpp TournamentSortTest.cpp)

target_link_libraries(SortMethodsTest SortMethods gtest gtest_main Threads::Threads)
enable_testing()
add_test(NAME SortMethodsTest COMMAND SortMethodsTest)

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS SortMethodsTest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests with CTest"
)