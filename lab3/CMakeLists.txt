cmake_minimum_required(VERSION 3.10.0)
project(BankSystem VERSION 0.1.0 LANGUAGES C CXX)

option(ENABLE_COVERAGE "Enable coverage reporting (requires gcovr)" ON)

if(ENABLE_COVERAGE)
    message(STATUS "Coverage instrumentation enabled")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

file(GLOB_RECURSE SOURCES
    "account/*.*"
    "banksafebox/*.*"
    "card/*.*"
    "customer/*.*"
    "datamanager/*.*"
    "exception/*.*"
    "generator/*.*"
    "getter/*.*"
    "money/*.*"
    "FAQ/*.*"
)

if(NOT SOURCES)
    message(WARNING "No excutable files found!")
endif()

add_library(BankSystem STATIC ${SOURCES})

target_include_directories(BankSystem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(GLOB_RECURSE TEST_SOURCES
    "test/*.cpp"
)

if(NOT TEST_SOURCES)
    message(WARNING "No test files found!")
endif()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(BankSystemTest ${TEST_SOURCES})

target_link_libraries(BankSystemTest BankSystem gtest gtest_main Threads::Threads)
enable_testing()
add_test(NAME BankSystemTest COMMAND BankSystemTest)

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS BankSystemTest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests with CTest"
)