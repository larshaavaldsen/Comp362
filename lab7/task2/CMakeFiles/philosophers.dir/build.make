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
CMAKE_SOURCE_DIR = /home/lars/comp362/lab7/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lars/comp362/lab7/task2

# Include any dependencies generated for this target.
include CMakeFiles/philosophers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/philosophers.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/philosophers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philosophers.dir/flags.make

CMakeFiles/philosophers.dir/philoWithTryLock.c.o: CMakeFiles/philosophers.dir/flags.make
CMakeFiles/philosophers.dir/philoWithTryLock.c.o: philoWithTryLock.c
CMakeFiles/philosophers.dir/philoWithTryLock.c.o: CMakeFiles/philosophers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/comp362/lab7/task2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philosophers.dir/philoWithTryLock.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/philosophers.dir/philoWithTryLock.c.o -MF CMakeFiles/philosophers.dir/philoWithTryLock.c.o.d -o CMakeFiles/philosophers.dir/philoWithTryLock.c.o -c /home/lars/comp362/lab7/task2/philoWithTryLock.c

CMakeFiles/philosophers.dir/philoWithTryLock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philosophers.dir/philoWithTryLock.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lars/comp362/lab7/task2/philoWithTryLock.c > CMakeFiles/philosophers.dir/philoWithTryLock.c.i

CMakeFiles/philosophers.dir/philoWithTryLock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philosophers.dir/philoWithTryLock.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lars/comp362/lab7/task2/philoWithTryLock.c -o CMakeFiles/philosophers.dir/philoWithTryLock.c.s

# Object files for target philosophers
philosophers_OBJECTS = \
"CMakeFiles/philosophers.dir/philoWithTryLock.c.o"

# External object files for target philosophers
philosophers_EXTERNAL_OBJECTS =

bin/philosophers: CMakeFiles/philosophers.dir/philoWithTryLock.c.o
bin/philosophers: CMakeFiles/philosophers.dir/build.make
bin/philosophers: CMakeFiles/philosophers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lars/comp362/lab7/task2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/philosophers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philosophers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philosophers.dir/build: bin/philosophers
.PHONY : CMakeFiles/philosophers.dir/build

CMakeFiles/philosophers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philosophers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philosophers.dir/clean

CMakeFiles/philosophers.dir/depend:
	cd /home/lars/comp362/lab7/task2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/comp362/lab7/task2 /home/lars/comp362/lab7/task2 /home/lars/comp362/lab7/task2 /home/lars/comp362/lab7/task2 /home/lars/comp362/lab7/task2/CMakeFiles/philosophers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philosophers.dir/depend

