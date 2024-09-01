#--------------------------- MAIN CONFIGURATION ---------------------------#

cmake_minimum_required(VERSION 3.6.0)
set(PROJECT_NAME multythreading_lab_1)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    SourceFiles/Core/Starter.cpp
    SourceFiles/Core/Starter.hpp
    SourceFiles/Core/BaseInfoDisplayer.cpp
    SourceFiles/Core/BaseInfoDisplayer.hpp
    SourceFiles/Launcher/LaboratoryStarter.cpp
    SourceFiles/Launcher/LaboratoryStarter.hpp
    SourceFiles/Tasks/Task1.cpp
    SourceFiles/Tasks/Task1.hpp
    SourceFiles/Tasks/Task2.cpp
    SourceFiles/Tasks/Task2.hpp
    SourceFiles/Tasks/Task3.cpp
    SourceFiles/Tasks/Task3.hpp
    SourceFiles/Tasks/Task4.cpp
    SourceFiles/Tasks/Task4.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE SourceFiles)

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