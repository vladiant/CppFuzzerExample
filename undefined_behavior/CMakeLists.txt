cmake_minimum_required(VERSION 3.11)

project(UndefinedBehavior LANGUAGES CXX)

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
   message(FATAL_ERROR "Compiler should be Clang")
endif()

add_executable(
    ${PROJECT_NAME}
    undefined_behavior.cpp
)

set_target_properties(
   ${PROJECT_NAME}
   PROPERTIES
      CXX_STANDARD 20
      CXX_STANDARD_REQUIRED YES
      CXX_EXTENSIONS NO
)

target_compile_options(
   ${PROJECT_NAME}
   PRIVATE
      $<$<CXX_COMPILER_ID:Clang>:-fsanitize=fuzzer,undefined>
)

target_link_libraries(
   ${PROJECT_NAME}
   PRIVATE
      $<$<CXX_COMPILER_ID:Clang>:-fsanitize=fuzzer,undefined>
)
