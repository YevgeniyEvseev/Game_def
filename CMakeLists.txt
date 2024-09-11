cmake_minimum_required(VERSION 3.5)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(Game_def)      

find_package(Curses REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)


include_directories(${CURSES_INCLUDE_DIR})

set(PROJECT_SOURCES
    games/tetris/QT_part/tetris/major.cpp
    games/tetris/QT_part/tetris/mainwindow.cpp
    games/tetris/QT_part/tetris/mainwindow.h
    games/tetris/QT_part/tetris/mainwindow.ui
    games/tetris/QT_part/tetris/Ogl_painter.cpp
    games/tetris/QT_part/tetris/Ogl_painter.h

    main.cpp
    games/sea_batle/sea_batle.cpp
    games/snake/QT_part/snake.cpp 
    games/tanks/tank.cpp
)

add_executable(Game_def ${PROJECT_SOURCES}
    # shared file
    
    GUI/cli/menu.c
    lib/proc_files.c
    GUI/cli/interface_console.c
    
    # tetris
    games/tetris/tetris.c
    games/tetris/backend/matrix_game.c
    games/tetris/backend/kernel.c  
    games/tetris/fronted/fronted.c  

    # tetris_qt
    

    #snake
    games/snake/snake.c 
    games/snake/backend/kernel.c
    games/snake/fronted/fronted.c
    
   

)

target_link_libraries("${PROJECT_NAME}" ${CURSES_LIBRARIES})
target_link_libraries("${PROJECT_NAME}" Qt6::Widgets)
target_link_libraries("${PROJECT_NAME}" Qt6::OpenGLWidgets)


