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
CMAKE_SOURCE_DIR = /home/lars/comp362/lab11/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lars/comp362/lab11/task1

# Include any dependencies generated for this target.
include CMakeFiles/disk_timer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/disk_timer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/disk_timer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/disk_timer.dir/flags.make

CMakeFiles/disk_timer.dir/disk.c.o: CMakeFiles/disk_timer.dir/flags.make
CMakeFiles/disk_timer.dir/disk.c.o: disk.c
CMakeFiles/disk_timer.dir/disk.c.o: CMakeFiles/disk_timer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/comp362/lab11/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/disk_timer.dir/disk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/disk_timer.dir/disk.c.o -MF CMakeFiles/disk_timer.dir/disk.c.o.d -o CMakeFiles/disk_timer.dir/disk.c.o -c /home/lars/comp362/lab11/task1/disk.c

CMakeFiles/disk_timer.dir/disk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/disk_timer.dir/disk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lars/comp362/lab11/task1/disk.c > CMakeFiles/disk_timer.dir/disk.c.i

CMakeFiles/disk_timer.dir/disk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/disk_timer.dir/disk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lars/comp362/lab11/task1/disk.c -o CMakeFiles/disk_timer.dir/disk.c.s

CMakeFiles/disk_timer.dir/test_disk.c.o: CMakeFiles/disk_timer.dir/flags.make
CMakeFiles/disk_timer.dir/test_disk.c.o: test_disk.c
CMakeFiles/disk_timer.dir/test_disk.c.o: CMakeFiles/disk_timer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lars/comp362/lab11/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/disk_timer.dir/test_disk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/disk_timer.dir/test_disk.c.o -MF CMakeFiles/disk_timer.dir/test_disk.c.o.d -o CMakeFiles/disk_timer.dir/test_disk.c.o -c /home/lars/comp362/lab11/task1/test_disk.c

CMakeFiles/disk_timer.dir/test_disk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/disk_timer.dir/test_disk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lars/comp362/lab11/task1/test_disk.c > CMakeFiles/disk_timer.dir/test_disk.c.i

CMakeFiles/disk_timer.dir/test_disk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/disk_timer.dir/test_disk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lars/comp362/lab11/task1/test_disk.c -o CMakeFiles/disk_timer.dir/test_disk.c.s

# Object files for target disk_timer
disk_timer_OBJECTS = \
"CMakeFiles/disk_timer.dir/disk.c.o" \
"CMakeFiles/disk_timer.dir/test_disk.c.o"

# External object files for target disk_timer
disk_timer_EXTERNAL_OBJECTS =

bin/disk_timer: CMakeFiles/disk_timer.dir/disk.c.o
bin/disk_timer: CMakeFiles/disk_timer.dir/test_disk.c.o
bin/disk_timer: CMakeFiles/disk_timer.dir/build.make
bin/disk_timer: CMakeFiles/disk_timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lars/comp362/lab11/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bin/disk_timer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/disk_timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/disk_timer.dir/build: bin/disk_timer
.PHONY : CMakeFiles/disk_timer.dir/build

CMakeFiles/disk_timer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/disk_timer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/disk_timer.dir/clean

CMakeFiles/disk_timer.dir/depend:
	cd /home/lars/comp362/lab11/task1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lars/comp362/lab11/task1 /home/lars/comp362/lab11/task1 /home/lars/comp362/lab11/task1 /home/lars/comp362/lab11/task1 /home/lars/comp362/lab11/task1/CMakeFiles/disk_timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/disk_timer.dir/depend
