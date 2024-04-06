#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME lab_3)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(
    CPP_SOURCES
    main.cpp
    Employee.cpp
    SalaryCalculator.cpp
    CommonTypes.cpp
    MainMenu.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${CPP_SOURCES}
)