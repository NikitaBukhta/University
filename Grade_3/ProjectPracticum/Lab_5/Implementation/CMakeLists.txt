#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME project_practicum_lab_5)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

file(GLOB CPP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(
    ${PROJECT_NAME}
    ${CPP_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})