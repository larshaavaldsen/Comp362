# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/build"

# Include any dependencies generated for this target.
include CMakeFiles/timer_posix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/timer_posix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/timer_posix.dir/flags.make

CMakeFiles/timer_posix.dir/timer_posix.c.o: CMakeFiles/timer_posix.dir/flags.make
CMakeFiles/timer_posix.dir/timer_posix.c.o: ../timer_posix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/timer_posix.dir/timer_posix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timer_posix.dir/timer_posix.c.o   -c "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/timer_posix.c"

CMakeFiles/timer_posix.dir/timer_posix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timer_posix.dir/timer_posix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/timer_posix.c" > CMakeFiles/timer_posix.dir/timer_posix.c.i

CMakeFiles/timer_posix.dir/timer_posix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timer_posix.dir/timer_posix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/timer_posix.c" -o CMakeFiles/timer_posix.dir/timer_posix.c.s

CMakeFiles/timer_posix.dir/timer_posix.c.o.requires:

.PHONY : CMakeFiles/timer_posix.dir/timer_posix.c.o.requires

CMakeFiles/timer_posix.dir/timer_posix.c.o.provides: CMakeFiles/timer_posix.dir/timer_posix.c.o.requires
	$(MAKE) -f CMakeFiles/timer_posix.dir/build.make CMakeFiles/timer_posix.dir/timer_posix.c.o.provides.build
.PHONY : CMakeFiles/timer_posix.dir/timer_posix.c.o.provides

CMakeFiles/timer_posix.dir/timer_posix.c.o.provides.build: CMakeFiles/timer_posix.dir/timer_posix.c.o


# Object files for target timer_posix
timer_posix_OBJECTS = \
"CMakeFiles/timer_posix.dir/timer_posix.c.o"

# External object files for target timer_posix
timer_posix_EXTERNAL_OBJECTS =

bin/timer_posix: CMakeFiles/timer_posix.dir/timer_posix.c.o
bin/timer_posix: CMakeFiles/timer_posix.dir/build.make
bin/timer_posix: CMakeFiles/timer_posix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/timer_posix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timer_posix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/timer_posix.dir/build: bin/timer_posix

.PHONY : CMakeFiles/timer_posix.dir/build

CMakeFiles/timer_posix.dir/requires: CMakeFiles/timer_posix.dir/timer_posix.c.o.requires

.PHONY : CMakeFiles/timer_posix.dir/requires

CMakeFiles/timer_posix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/timer_posix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/timer_posix.dir/clean

CMakeFiles/timer_posix.dir/depend:
	cd "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer" "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer" "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/build" "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/build" "/media/psf/Dropbox for Business/Teaching/Fall2018/COMP362-F18/labSols/proj02Sol/timer/build/CMakeFiles/timer_posix.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/timer_posix.dir/depend

