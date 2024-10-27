#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME lab_5_multythreading)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(CPP_SOURCE_DIR "SourceFiles")
set(
  CPP_SOURCES
  ${CPP_SOURCE_DIR}/main.cpp
  ${CPP_SOURCE_DIR}/ThreadPool.hpp
  ${CPP_SOURCE_DIR}/ThreadPool.cpp
)


add_executable(
  ${PROJECT_NAME}
  ${CPP_SOURCES}
)