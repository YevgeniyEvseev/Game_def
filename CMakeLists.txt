cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME test_cmake)
project("${PROJECT_NAME}")      

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable("${PROJECT_NAME}"
    # shared file
    main.c
    GUI/cli/menu.c
    lib/proc_files.c
    GUI/cli/interface_console.c
    
    # tetris
    games/tetris/tetris.c
    games/tetris/backend/matrix_game.c
    games/tetris/backend/kernel.c  
    games/tetris/fronted/fronted.c  

    #snake
    games/snake/snake.c 
    games/snake/backend/kernel.c
    
    games/sea_batle/sea_batle.c
  
    games/tanks/tank.c
    
    



)

target_link_libraries("${PROJECT_NAME}" ${CURSES_LIBRARIES})