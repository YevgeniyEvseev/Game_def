cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test_cmake)
project("${PROJECT_NAME}")      

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable("${PROJECT_NAME}"
    main.c
    games/tetris/tetris.c
    GUI/cli/base.c
    games/sea_batle/sea_batle.c
    games/snake/snake.c 
    games/tanks/tank.c
    games/tetris/backend/kernel.c
    games/tetris/backend/matrix_game.c 
    games/tetris/backend/proc_files.c 
    games/tetris/fronted/fronted.c 

)

target_link_libraries("${PROJECT_NAME}" ${CURSES_LIBRARIES})