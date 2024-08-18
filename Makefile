# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dotharer/Documents/learn/GITHUB/Game_def

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dotharer/Documents/learn/GITHUB/Game_def

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dotharer/Documents/learn/GITHUB/Game_def/CMakeFiles /home/dotharer/Documents/learn/GITHUB/Game_def//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dotharer/Documents/learn/GITHUB/Game_def/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test_cmake

# Build rule for target.
test_cmake: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_cmake
.PHONY : test_cmake

# fast build rule for target.
test_cmake/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/build
.PHONY : test_cmake/fast

GUI/cli/base.o: GUI/cli/base.c.o
.PHONY : GUI/cli/base.o

# target to build an object file
GUI/cli/base.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/GUI/cli/base.c.o
.PHONY : GUI/cli/base.c.o

GUI/cli/base.i: GUI/cli/base.c.i
.PHONY : GUI/cli/base.i

# target to preprocess a source file
GUI/cli/base.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/GUI/cli/base.c.i
.PHONY : GUI/cli/base.c.i

GUI/cli/base.s: GUI/cli/base.c.s
.PHONY : GUI/cli/base.s

# target to generate assembly for a file
GUI/cli/base.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/GUI/cli/base.c.s
.PHONY : GUI/cli/base.c.s

games/sea_batle/sea_batle.o: games/sea_batle/sea_batle.c.o
.PHONY : games/sea_batle/sea_batle.o

# target to build an object file
games/sea_batle/sea_batle.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/sea_batle/sea_batle.c.o
.PHONY : games/sea_batle/sea_batle.c.o

games/sea_batle/sea_batle.i: games/sea_batle/sea_batle.c.i
.PHONY : games/sea_batle/sea_batle.i

# target to preprocess a source file
games/sea_batle/sea_batle.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/sea_batle/sea_batle.c.i
.PHONY : games/sea_batle/sea_batle.c.i

games/sea_batle/sea_batle.s: games/sea_batle/sea_batle.c.s
.PHONY : games/sea_batle/sea_batle.s

# target to generate assembly for a file
games/sea_batle/sea_batle.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/sea_batle/sea_batle.c.s
.PHONY : games/sea_batle/sea_batle.c.s

games/snake/snake.o: games/snake/snake.c.o
.PHONY : games/snake/snake.o

# target to build an object file
games/snake/snake.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/snake/snake.c.o
.PHONY : games/snake/snake.c.o

games/snake/snake.i: games/snake/snake.c.i
.PHONY : games/snake/snake.i

# target to preprocess a source file
games/snake/snake.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/snake/snake.c.i
.PHONY : games/snake/snake.c.i

games/snake/snake.s: games/snake/snake.c.s
.PHONY : games/snake/snake.s

# target to generate assembly for a file
games/snake/snake.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/snake/snake.c.s
.PHONY : games/snake/snake.c.s

games/tanks/tank.o: games/tanks/tank.c.o
.PHONY : games/tanks/tank.o

# target to build an object file
games/tanks/tank.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tanks/tank.c.o
.PHONY : games/tanks/tank.c.o

games/tanks/tank.i: games/tanks/tank.c.i
.PHONY : games/tanks/tank.i

# target to preprocess a source file
games/tanks/tank.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tanks/tank.c.i
.PHONY : games/tanks/tank.c.i

games/tanks/tank.s: games/tanks/tank.c.s
.PHONY : games/tanks/tank.s

# target to generate assembly for a file
games/tanks/tank.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tanks/tank.c.s
.PHONY : games/tanks/tank.c.s

games/tetris/backend/kernel.o: games/tetris/backend/kernel.c.o
.PHONY : games/tetris/backend/kernel.o

# target to build an object file
games/tetris/backend/kernel.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/kernel.c.o
.PHONY : games/tetris/backend/kernel.c.o

games/tetris/backend/kernel.i: games/tetris/backend/kernel.c.i
.PHONY : games/tetris/backend/kernel.i

# target to preprocess a source file
games/tetris/backend/kernel.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/kernel.c.i
.PHONY : games/tetris/backend/kernel.c.i

games/tetris/backend/kernel.s: games/tetris/backend/kernel.c.s
.PHONY : games/tetris/backend/kernel.s

# target to generate assembly for a file
games/tetris/backend/kernel.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/kernel.c.s
.PHONY : games/tetris/backend/kernel.c.s

games/tetris/backend/matrix_game.o: games/tetris/backend/matrix_game.c.o
.PHONY : games/tetris/backend/matrix_game.o

# target to build an object file
games/tetris/backend/matrix_game.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/matrix_game.c.o
.PHONY : games/tetris/backend/matrix_game.c.o

games/tetris/backend/matrix_game.i: games/tetris/backend/matrix_game.c.i
.PHONY : games/tetris/backend/matrix_game.i

# target to preprocess a source file
games/tetris/backend/matrix_game.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/matrix_game.c.i
.PHONY : games/tetris/backend/matrix_game.c.i

games/tetris/backend/matrix_game.s: games/tetris/backend/matrix_game.c.s
.PHONY : games/tetris/backend/matrix_game.s

# target to generate assembly for a file
games/tetris/backend/matrix_game.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/matrix_game.c.s
.PHONY : games/tetris/backend/matrix_game.c.s

games/tetris/backend/proc_files.o: games/tetris/backend/proc_files.c.o
.PHONY : games/tetris/backend/proc_files.o

# target to build an object file
games/tetris/backend/proc_files.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/proc_files.c.o
.PHONY : games/tetris/backend/proc_files.c.o

games/tetris/backend/proc_files.i: games/tetris/backend/proc_files.c.i
.PHONY : games/tetris/backend/proc_files.i

# target to preprocess a source file
games/tetris/backend/proc_files.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/proc_files.c.i
.PHONY : games/tetris/backend/proc_files.c.i

games/tetris/backend/proc_files.s: games/tetris/backend/proc_files.c.s
.PHONY : games/tetris/backend/proc_files.s

# target to generate assembly for a file
games/tetris/backend/proc_files.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/backend/proc_files.c.s
.PHONY : games/tetris/backend/proc_files.c.s

games/tetris/fronted/fronted.o: games/tetris/fronted/fronted.c.o
.PHONY : games/tetris/fronted/fronted.o

# target to build an object file
games/tetris/fronted/fronted.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/fronted/fronted.c.o
.PHONY : games/tetris/fronted/fronted.c.o

games/tetris/fronted/fronted.i: games/tetris/fronted/fronted.c.i
.PHONY : games/tetris/fronted/fronted.i

# target to preprocess a source file
games/tetris/fronted/fronted.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/fronted/fronted.c.i
.PHONY : games/tetris/fronted/fronted.c.i

games/tetris/fronted/fronted.s: games/tetris/fronted/fronted.c.s
.PHONY : games/tetris/fronted/fronted.s

# target to generate assembly for a file
games/tetris/fronted/fronted.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/fronted/fronted.c.s
.PHONY : games/tetris/fronted/fronted.c.s

games/tetris/tetris.o: games/tetris/tetris.c.o
.PHONY : games/tetris/tetris.o

# target to build an object file
games/tetris/tetris.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/tetris.c.o
.PHONY : games/tetris/tetris.c.o

games/tetris/tetris.i: games/tetris/tetris.c.i
.PHONY : games/tetris/tetris.i

# target to preprocess a source file
games/tetris/tetris.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/tetris.c.i
.PHONY : games/tetris/tetris.c.i

games/tetris/tetris.s: games/tetris/tetris.c.s
.PHONY : games/tetris/tetris.s

# target to generate assembly for a file
games/tetris/tetris.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/games/tetris/tetris.c.s
.PHONY : games/tetris/tetris.c.s

main.o: main.c.o
.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i
.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s
.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_cmake.dir/build.make CMakeFiles/test_cmake.dir/main.c.s
.PHONY : main.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... test_cmake"
	@echo "... GUI/cli/base.o"
	@echo "... GUI/cli/base.i"
	@echo "... GUI/cli/base.s"
	@echo "... games/sea_batle/sea_batle.o"
	@echo "... games/sea_batle/sea_batle.i"
	@echo "... games/sea_batle/sea_batle.s"
	@echo "... games/snake/snake.o"
	@echo "... games/snake/snake.i"
	@echo "... games/snake/snake.s"
	@echo "... games/tanks/tank.o"
	@echo "... games/tanks/tank.i"
	@echo "... games/tanks/tank.s"
	@echo "... games/tetris/backend/kernel.o"
	@echo "... games/tetris/backend/kernel.i"
	@echo "... games/tetris/backend/kernel.s"
	@echo "... games/tetris/backend/matrix_game.o"
	@echo "... games/tetris/backend/matrix_game.i"
	@echo "... games/tetris/backend/matrix_game.s"
	@echo "... games/tetris/backend/proc_files.o"
	@echo "... games/tetris/backend/proc_files.i"
	@echo "... games/tetris/backend/proc_files.s"
	@echo "... games/tetris/fronted/fronted.o"
	@echo "... games/tetris/fronted/fronted.i"
	@echo "... games/tetris/fronted/fronted.s"
	@echo "... games/tetris/tetris.o"
	@echo "... games/tetris/tetris.i"
	@echo "... games/tetris/tetris.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

