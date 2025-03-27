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
CMAKE_SOURCE_DIR = "/home/bandolero/Área de trabalho/Github/rogue-sfml"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/bandolero/Área de trabalho/Github/rogue-sfml"

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
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/bandolero/Área de trabalho/Github/rogue-sfml/CMakeFiles" "/home/bandolero/Área de trabalho/Github/rogue-sfml//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/bandolero/Área de trabalho/Github/rogue-sfml/CMakeFiles" 0
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
# Target rules for targets named rogue-sfml

# Build rule for target.
rogue-sfml: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 rogue-sfml
.PHONY : rogue-sfml

# fast build rule for target.
rogue-sfml/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/build
.PHONY : rogue-sfml/fast

#=============================================================================
# Target rules for targets named clean-all

# Build rule for target.
clean-all: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean-all
.PHONY : clean-all

# fast build rule for target.
clean-all/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/clean-all.dir/build.make CMakeFiles/clean-all.dir/build
.PHONY : clean-all/fast

src/Inimigo.o: src/Inimigo.cpp.o
.PHONY : src/Inimigo.o

# target to build an object file
src/Inimigo.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Inimigo.cpp.o
.PHONY : src/Inimigo.cpp.o

src/Inimigo.i: src/Inimigo.cpp.i
.PHONY : src/Inimigo.i

# target to preprocess a source file
src/Inimigo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Inimigo.cpp.i
.PHONY : src/Inimigo.cpp.i

src/Inimigo.s: src/Inimigo.cpp.s
.PHONY : src/Inimigo.s

# target to generate assembly for a file
src/Inimigo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Inimigo.cpp.s
.PHONY : src/Inimigo.cpp.s

src/Jogador.o: src/Jogador.cpp.o
.PHONY : src/Jogador.o

# target to build an object file
src/Jogador.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Jogador.cpp.o
.PHONY : src/Jogador.cpp.o

src/Jogador.i: src/Jogador.cpp.i
.PHONY : src/Jogador.i

# target to preprocess a source file
src/Jogador.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Jogador.cpp.i
.PHONY : src/Jogador.cpp.i

src/Jogador.s: src/Jogador.cpp.s
.PHONY : src/Jogador.s

# target to generate assembly for a file
src/Jogador.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Jogador.cpp.s
.PHONY : src/Jogador.cpp.s

src/Jogo.o: src/Jogo.cpp.o
.PHONY : src/Jogo.o

# target to build an object file
src/Jogo.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Jogo.cpp.o
.PHONY : src/Jogo.cpp.o

src/Jogo.i: src/Jogo.cpp.i
.PHONY : src/Jogo.i

# target to preprocess a source file
src/Jogo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Jogo.cpp.i
.PHONY : src/Jogo.cpp.i

src/Jogo.s: src/Jogo.cpp.s
.PHONY : src/Jogo.s

# target to generate assembly for a file
src/Jogo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Jogo.cpp.s
.PHONY : src/Jogo.cpp.s

src/Projetil.o: src/Projetil.cpp.o
.PHONY : src/Projetil.o

# target to build an object file
src/Projetil.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Projetil.cpp.o
.PHONY : src/Projetil.cpp.o

src/Projetil.i: src/Projetil.cpp.i
.PHONY : src/Projetil.i

# target to preprocess a source file
src/Projetil.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Projetil.cpp.i
.PHONY : src/Projetil.cpp.i

src/Projetil.s: src/Projetil.cpp.s
.PHONY : src/Projetil.s

# target to generate assembly for a file
src/Projetil.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/Projetil.cpp.s
.PHONY : src/Projetil.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/rogue-sfml.dir/build.make CMakeFiles/rogue-sfml.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... clean-all"
	@echo "... rogue-sfml"
	@echo "... src/Inimigo.o"
	@echo "... src/Inimigo.i"
	@echo "... src/Inimigo.s"
	@echo "... src/Jogador.o"
	@echo "... src/Jogador.i"
	@echo "... src/Jogador.s"
	@echo "... src/Jogo.o"
	@echo "... src/Jogo.i"
	@echo "... src/Jogo.s"
	@echo "... src/Projetil.o"
	@echo "... src/Projetil.i"
	@echo "... src/Projetil.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

