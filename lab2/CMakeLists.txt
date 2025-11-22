cmake_minimum_required(VERSION 3.10.0)
project(SportClub VERSION 0.1.0 LANGUAGES C CXX)

option(ENABLE_COVERAGE "Enable coverage reporting (requires gcovr)" ON)

if(ENABLE_COVERAGE)
    message(STATUS "Coverage instrumentation enabled")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

file(GLOB_RECURSE SOURCES
    "Exception/*.*"
    "Human/*.*"
    "Mirror/*.*"
    "Reception/*.*"
    "Room/*.*"
    "Schedule/*.*"
    "Shop/*.*"
    "SM/*.*"
)

if(NOT SOURCES)
    message(WARNING "No excutable files found!")
endif()

add_library(SportClub STATIC ${SOURCES})

target_include_directories(SportClub PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

file(GLOB_RECURSE TEST_SOURCES
    "Test/*.cpp"
)

if(NOT TEST_SOURCES)
    message(WARNING "No test files found!")
endif()

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(SportClubTest ${TEST_SOURCES})

target_link_libraries(SportClubTest SportClub gtest gtest_main Threads::Threads)
enable_testing()
add_test(NAME SportClubTest COMMAND SportClubTest)

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS SportClubTest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running tests with CTest"
)

#if(ENABLE_COVERAGE)
#    find_program(GCOVR_PATH gcovr)
#
#    if(NOT GCOVR_PATH) 
#        message(WARNING "gcovr not found. Install via: pip install gcovr")
#    else()
#        set(GCOVR_OUTPUT_DIR ${CMAKE_BINARY_DIR}/coverage)
#        file(MAKE_DIRECTORY ${GCOVR_OUTPUT_DIR})
#
#        add_custom_target(coverage
#            COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
#            COMMAND ${GCOVR_PATH} 
#                -r ${CMAKE_SOURCE_DIR} 
#                --html 
#                --html-details 
#                --html-theme "green"
#                --html-self-contained
#                #-o ${GCOVR_OUTPUT_DIR}/coverage.html 
#                --exclude= ".*test.*" 
#                --exclude= ".*tests.*"
#                --exclude="${CMAKE_BINARY_DIR}"
#
#            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#            DEPENDS SportClubTest
#            COMMENT "Generating coverage report with gcovr..."
#        )
#    endif()
#endif()