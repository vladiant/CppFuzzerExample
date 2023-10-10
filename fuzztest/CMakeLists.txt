cmake_minimum_required(VERSION 3.10)

project(FuzztestExample LANGUAGES CXX)

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
   message(FATAL_ERROR "Compiler should be Clang")
endif()

add_subdirectory(fuzztest)

enable_testing()

include(GoogleTest)

# Fuzzing mode and compatibility mode
fuzztest_setup_fuzzing_flags()

add_executable(
    ${PROJECT_NAME}
        main.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

link_fuzztest(${PROJECT_NAME})

gtest_discover_tests(${PROJECT_NAME})

