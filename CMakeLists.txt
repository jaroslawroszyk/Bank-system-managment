cmake_minimum_required(VERSION 3.0.0)
project(BankSystem VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(BankSystem main.cpp bank.cpp functiontobank.cpp loginsystem.cpp systembank.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
