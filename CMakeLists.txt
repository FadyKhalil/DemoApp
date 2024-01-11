cmake_minimum_required(VERSION 3.22)

project(calculator
        DESCRIPTION "my calculator using thread")


add_executable(${PROJECT_NAME} main.cpp)

set(START 2)
set(PRINT_ID_2 1)
set(SIZE_LOOP 100000U)
set(INPUT_1 2U)
set(INPUT_2 3U)


# Configure the header file
configure_file(${CMAKE_HOME_DIRECTORY}/include/config.h.in ${CMAKE_HOME_DIRECTORY}/include/config.h)

add_subdirectory(${CMAKE_HOME_DIRECTORY}/lib)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE class)