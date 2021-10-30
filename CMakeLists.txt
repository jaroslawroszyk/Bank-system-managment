cmake_minimum_required(VERSION 3.17)

project(BankSystem VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(FATAL_ERROR "Available build types: Debug and Release.")
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(BankSystem
    src/main.cpp
    src/account.cpp
    src/functiontobank.cpp
    src/loginsystem.cpp
    src/systembank.cpp
        src/CliInput.cpp)

set_target_properties(BankSystem
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(BankSystem
                PUBLIC
                -O3 -g3 -Wall -Wextra -pedantic -Werror -Wno-unused-parameter -Wunused
            )
    endif()
else()
    if(MSVC)
        #ToDo: add flags for msfc
    else()
        target_compile_options(BankSystem
                PUBLIC
                -O3 -Wall -Wextra -pedantic
            )
    endif()
endif()
