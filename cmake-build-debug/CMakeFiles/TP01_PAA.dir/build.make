# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\vburi\Documents\UFV\PAA\TP01-PAA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TP01_PAA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP01_PAA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP01_PAA.dir/flags.make

CMakeFiles/TP01_PAA.dir/main.c.obj: CMakeFiles/TP01_PAA.dir/flags.make
CMakeFiles/TP01_PAA.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP01_PAA.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP01_PAA.dir\main.c.obj   -c C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\main.c

CMakeFiles/TP01_PAA.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP01_PAA.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\main.c > CMakeFiles\TP01_PAA.dir\main.c.i

CMakeFiles/TP01_PAA.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP01_PAA.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\main.c -o CMakeFiles\TP01_PAA.dir\main.c.s

# Object files for target TP01_PAA
TP01_PAA_OBJECTS = \
"CMakeFiles/TP01_PAA.dir/main.c.obj"

# External object files for target TP01_PAA
TP01_PAA_EXTERNAL_OBJECTS =

TP01_PAA.exe: CMakeFiles/TP01_PAA.dir/main.c.obj
TP01_PAA.exe: CMakeFiles/TP01_PAA.dir/build.make
TP01_PAA.exe: CMakeFiles/TP01_PAA.dir/linklibs.rsp
TP01_PAA.exe: CMakeFiles/TP01_PAA.dir/objects1.rsp
TP01_PAA.exe: CMakeFiles/TP01_PAA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TP01_PAA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TP01_PAA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP01_PAA.dir/build: TP01_PAA.exe

.PHONY : CMakeFiles/TP01_PAA.dir/build

CMakeFiles/TP01_PAA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TP01_PAA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TP01_PAA.dir/clean

CMakeFiles/TP01_PAA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\vburi\Documents\UFV\PAA\TP01-PAA C:\Users\vburi\Documents\UFV\PAA\TP01-PAA C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\cmake-build-debug C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\cmake-build-debug C:\Users\vburi\Documents\UFV\PAA\TP01-PAA\cmake-build-debug\CMakeFiles\TP01_PAA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP01_PAA.dir/depend

