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
CMAKE_SOURCE_DIR = /home/lars/comp362/lab9/dynamically

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lars/comp362/lab9/dynamically

# Include any dependencies generated for this target.
include CMakeFiles/inverted.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/inverted.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/inverted.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inverted.dir/flags.make

CMakeFiles/inverted.dir/src/inverted.c.o: CMakeFiles/inverted.dir/flags.make
CMakeFiles/inverted.dir/src/inverted.c.o: src/inverted.c
CMakeFiles/inverted.dir/src/inverted.c.o: CMakeFiles/inverted.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/comp362/lab9/dynamically/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/inverted.dir/src/inverted.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/inverted.dir/src/inverted.c.o -MF CMakeFiles/inverted.dir/src/inverted.c.o.d -o CMakeFiles/inverted.dir/src/inverted.c.o -c /home/lars/comp362/lab9/dynamically/src/inverted.c

CMakeFiles/inverted.dir/src/inverted.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inverted.dir/src/inverted.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lars/comp362/lab9/dynamically/src/inverted.c > CMakeFiles/inverted.dir/src/inverted.c.i

CMakeFiles/inverted.dir/src/inverted.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inverted.dir/src/inverted.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lars/comp362/lab9/dynamically/src/inverted.c -o CMakeFiles/inverted.dir/src/inverted.c.s

# Object files for target inverted
inverted_OBJECTS = \
"CMakeFiles/inverted.dir/src/inverted.c.o"

# External object files for target inverted
inverted_EXTERNAL_OBJECTS =

lib/libinverted.so: CMakeFiles/inverted.dir/src/inverted.c.o
lib/libinverted.so: CMakeFiles/inverted.dir/build.make
lib/libinverted.so: CMakeFiles/inverted.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lars/comp362/lab9/dynamically/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library lib/libinverted.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inverted.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inverted.dir/build: lib/libinverted.so
.PHONY : CMakeFiles/inverted.dir/build

CMakeFiles/inverted.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inverted.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inverted.dir/clean

CMakeFiles/inverted.dir/depend:
	cd /home/lars/comp362/lab9/dynamically && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/comp362/lab9/dynamically /home/lars/comp362/lab9/dynamically /home/lars/comp362/lab9/dynamically /home/lars/comp362/lab9/dynamically /home/lars/comp362/lab9/dynamically/CMakeFiles/inverted.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inverted.dir/depend

