cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test_cmake)
project("${PROJECT_NAME}")      #устанавливаем имя проекта

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable("${PROJECT_NAME}"
    main.c
#    tetris/tetris.c
    GUI/cli/base.c
)

target_link_libraries("${PROJECT_NAME}" ${CURSES_LIBRARIES})