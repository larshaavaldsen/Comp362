# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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
CMAKE_SOURCE_DIR = /home/lars/comp362/lab4/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lars/comp362/lab4/task1

# Include any dependencies generated for this target.
include CMakeFiles/pipe1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pipe1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pipe1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipe1.dir/flags.make

CMakeFiles/pipe1.dir/pipes/pipe_1.c.o: CMakeFiles/pipe1.dir/flags.make
CMakeFiles/pipe1.dir/pipes/pipe_1.c.o: pipes/pipe_1.c
CMakeFiles/pipe1.dir/pipes/pipe_1.c.o: CMakeFiles/pipe1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/comp362/lab4/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pipe1.dir/pipes/pipe_1.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/pipe1.dir/pipes/pipe_1.c.o -MF CMakeFiles/pipe1.dir/pipes/pipe_1.c.o.d -o CMakeFiles/pipe1.dir/pipes/pipe_1.c.o -c /home/lars/comp362/lab4/task1/pipes/pipe_1.c

CMakeFiles/pipe1.dir/pipes/pipe_1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pipe1.dir/pipes/pipe_1.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lars/comp362/lab4/task1/pipes/pipe_1.c > CMakeFiles/pipe1.dir/pipes/pipe_1.c.i

CMakeFiles/pipe1.dir/pipes/pipe_1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pipe1.dir/pipes/pipe_1.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lars/comp362/lab4/task1/pipes/pipe_1.c -o CMakeFiles/pipe1.dir/pipes/pipe_1.c.s

# Object files for target pipe1
pipe1_OBJECTS = \
"CMakeFiles/pipe1.dir/pipes/pipe_1.c.o"

# External object files for target pipe1
pipe1_EXTERNAL_OBJECTS =

bin/pipe1: CMakeFiles/pipe1.dir/pipes/pipe_1.c.o
bin/pipe1: CMakeFiles/pipe1.dir/build.make
bin/pipe1: CMakeFiles/pipe1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lars/comp362/lab4/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/pipe1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipe1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipe1.dir/build: bin/pipe1
.PHONY : CMakeFiles/pipe1.dir/build

CMakeFiles/pipe1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pipe1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pipe1.dir/clean

CMakeFiles/pipe1.dir/depend:
	cd /home/lars/comp362/lab4/task1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/comp362/lab4/task1 /home/lars/comp362/lab4/task1 /home/lars/comp362/lab4/task1 /home/lars/comp362/lab4/task1 /home/lars/comp362/lab4/task1/CMakeFiles/pipe1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pipe1.dir/depend

