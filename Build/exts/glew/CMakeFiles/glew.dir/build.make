# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/benves-7/Documents/Clion/clion-2019.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/benves-7/Documents/Clion/clion-2019.2.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/benves-7/Documents/School/lab-env

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/benves-7/Documents/School/lab-env/Build

# Include any dependencies generated for this target.
include exts/glew/CMakeFiles/glew.dir/depend.make

# Include the progress variables for this target.
include exts/glew/CMakeFiles/glew.dir/progress.make

# Include the compile flags for this target's objects.
include exts/glew/CMakeFiles/glew.dir/flags.make

exts/glew/CMakeFiles/glew.dir/src/glew.c.o: exts/glew/CMakeFiles/glew.dir/flags.make
exts/glew/CMakeFiles/glew.dir/src/glew.c.o: ../exts/glew/src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/benves-7/Documents/School/lab-env/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object exts/glew/CMakeFiles/glew.dir/src/glew.c.o"
	cd /home/benves-7/Documents/School/lab-env/Build/exts/glew && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glew.dir/src/glew.c.o   -c /home/benves-7/Documents/School/lab-env/exts/glew/src/glew.c

exts/glew/CMakeFiles/glew.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/src/glew.c.i"
	cd /home/benves-7/Documents/School/lab-env/Build/exts/glew && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/benves-7/Documents/School/lab-env/exts/glew/src/glew.c > CMakeFiles/glew.dir/src/glew.c.i

exts/glew/CMakeFiles/glew.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/src/glew.c.s"
	cd /home/benves-7/Documents/School/lab-env/Build/exts/glew && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/benves-7/Documents/School/lab-env/exts/glew/src/glew.c -o CMakeFiles/glew.dir/src/glew.c.s

# Object files for target glew
glew_OBJECTS = \
"CMakeFiles/glew.dir/src/glew.c.o"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

exts/glew/libglew.a: exts/glew/CMakeFiles/glew.dir/src/glew.c.o
exts/glew/libglew.a: exts/glew/CMakeFiles/glew.dir/build.make
exts/glew/libglew.a: exts/glew/CMakeFiles/glew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/benves-7/Documents/School/lab-env/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libglew.a"
	cd /home/benves-7/Documents/School/lab-env/Build/exts/glew && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean_target.cmake
	cd /home/benves-7/Documents/School/lab-env/Build/exts/glew && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exts/glew/CMakeFiles/glew.dir/build: exts/glew/libglew.a

.PHONY : exts/glew/CMakeFiles/glew.dir/build

exts/glew/CMakeFiles/glew.dir/clean:
	cd /home/benves-7/Documents/School/lab-env/Build/exts/glew && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean.cmake
.PHONY : exts/glew/CMakeFiles/glew.dir/clean

exts/glew/CMakeFiles/glew.dir/depend:
	cd /home/benves-7/Documents/School/lab-env/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/benves-7/Documents/School/lab-env /home/benves-7/Documents/School/lab-env/exts/glew /home/benves-7/Documents/School/lab-env/Build /home/benves-7/Documents/School/lab-env/Build/exts/glew /home/benves-7/Documents/School/lab-env/Build/exts/glew/CMakeFiles/glew.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : exts/glew/CMakeFiles/glew.dir/depend

