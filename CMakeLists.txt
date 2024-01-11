cmake_minimum_required(VERSION 3.22)

project(calculator
        DESCRIPTION "my calculator using thread")


add_executable(${PROJECT_NAME} main.cpp)

if(${START_VALUE})
        set(START "${START_VALUE}U")
else()
        set(START 0)
endif()

if(${PRINT_VALUE})
        set(PRINT_ID_2 "${PRINT_VALUE}U")
else()
        set(PRINT_ID_2 1)
endif()

if(${SIZE_VALUE})
        set(SIZE_LOOP "${SIZE_VALUE}U")
else()
        set(SIZE_LOOP 100000U)
endif()

if(${INPUT_1_VALUE})
        set(INPUT_1 "${INPUT_1_VALUE}U")
else()
        set(INPUT_1 5U)
endif()

if(${INPUT_2_VALUE})
        set(INPUT_2 "${INPUT_2_VALUE}U")
else()
        set(INPUT_2 10U)
endif()


# Configure the header file
configure_file(${CMAKE_HOME_DIRECTORY}/include/config.h.in ${CMAKE_HOME_DIRECTORY}/include/config.h)

add_subdirectory(${CMAKE_HOME_DIRECTORY}/lib)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PRIVATE class)