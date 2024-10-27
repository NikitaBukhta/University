#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME lab_4_multythreading)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

set(CPP_SOURCE_DIR "SourceFiles")

set(
  CPP_SOURCES
  ${CPP_SOURCE_DIR}/main.cpp
  ${CPP_SOURCE_DIR}/NewThread.hpp
  ${CPP_SOURCE_DIR}/NewThread.cpp
  ${CPP_SOURCE_DIR}/WorkerRunnable.hpp
  ${CPP_SOURCE_DIR}/WorkerRunnable.cpp
  ${CPP_SOURCE_DIR}/ExperementalObject.hpp
  ${CPP_SOURCE_DIR}/ExperementalObject.cpp
)

add_executable(
  ${PROJECT_NAME}
  ${CPP_SOURCES}
)

#link QT6

find_package(Qt6 REQUIRED COMPONENTS Core)
# Add the Qt 6 include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt6Core_INCLUDE_DIRS} ${Qt6Widgets_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)

# Verify the minimum required version of Qt
if(Qt6_FOUND)
  if(Qt6_VERSION VERSION_LESS 6.0.0)
    message(FATAL_ERROR "Minimum required version of Qt is 6.0.0")
  endif()
else()
  message(FATAL_ERROR "Qt6 package not found. Please ensure Qt 6 is installed.")
endif()

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
)