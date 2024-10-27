#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME lab_2_multytheading)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(CPP_SOURCES_DIR "SourceFiles")
set(CPP_SOURCES
    ${CPP_SOURCES_DIR}/main.cpp
    ${CPP_SOURCES_DIR}/common.cpp
    ${CPP_SOURCES_DIR}/common.hpp
    ${CPP_SOURCES_DIR}/Student.cpp
    ${CPP_SOURCES_DIR}/Student.hpp
)

add_executable(
    ${PROJECT_NAME}
    ${CPP_SOURCES}
)