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
CMAKE_SOURCE_DIR = /home/lars/comp362/lab9/statically

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lars/comp362/lab9/statically

# Include any dependencies generated for this target.
include CMakeFiles/testInverted.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testInverted.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testInverted.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testInverted.dir/flags.make

CMakeFiles/testInverted.dir/src/testInverted.c.o: CMakeFiles/testInverted.dir/flags.make
CMakeFiles/testInverted.dir/src/testInverted.c.o: src/testInverted.c
CMakeFiles/testInverted.dir/src/testInverted.c.o: CMakeFiles/testInverted.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/comp362/lab9/statically/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/testInverted.dir/src/testInverted.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/testInverted.dir/src/testInverted.c.o -MF CMakeFiles/testInverted.dir/src/testInverted.c.o.d -o CMakeFiles/testInverted.dir/src/testInverted.c.o -c /home/lars/comp362/lab9/statically/src/testInverted.c

CMakeFiles/testInverted.dir/src/testInverted.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testInverted.dir/src/testInverted.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lars/comp362/lab9/statically/src/testInverted.c > CMakeFiles/testInverted.dir/src/testInverted.c.i

CMakeFiles/testInverted.dir/src/testInverted.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testInverted.dir/src/testInverted.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lars/comp362/lab9/statically/src/testInverted.c -o CMakeFiles/testInverted.dir/src/testInverted.c.s

# Object files for target testInverted
testInverted_OBJECTS = \
"CMakeFiles/testInverted.dir/src/testInverted.c.o"

# External object files for target testInverted
testInverted_EXTERNAL_OBJECTS =

bin/testInverted: CMakeFiles/testInverted.dir/src/testInverted.c.o
bin/testInverted: CMakeFiles/testInverted.dir/build.make
bin/testInverted: lib/libinverted.a
bin/testInverted: CMakeFiles/testInverted.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lars/comp362/lab9/statically/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/testInverted"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testInverted.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testInverted.dir/build: bin/testInverted
.PHONY : CMakeFiles/testInverted.dir/build

CMakeFiles/testInverted.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testInverted.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testInverted.dir/clean

CMakeFiles/testInverted.dir/depend:
	cd /home/lars/comp362/lab9/statically && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/comp362/lab9/statically /home/lars/comp362/lab9/statically /home/lars/comp362/lab9/statically /home/lars/comp362/lab9/statically /home/lars/comp362/lab9/statically/CMakeFiles/testInverted.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testInverted.dir/depend

