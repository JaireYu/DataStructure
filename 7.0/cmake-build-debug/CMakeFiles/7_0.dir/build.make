# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2018.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\C language learn\7.0"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\C language learn\7.0\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/7_0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/7_0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/7_0.dir/flags.make

CMakeFiles/7_0.dir/main.cpp.obj: CMakeFiles/7_0.dir/flags.make
CMakeFiles/7_0.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\C language learn\7.0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/7_0.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\7_0.dir\main.cpp.obj -c "D:\C language learn\7.0\main.cpp"

CMakeFiles/7_0.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/7_0.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\C language learn\7.0\main.cpp" > CMakeFiles\7_0.dir\main.cpp.i

CMakeFiles/7_0.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/7_0.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\C language learn\7.0\main.cpp" -o CMakeFiles\7_0.dir\main.cpp.s

# Object files for target 7_0
7_0_OBJECTS = \
"CMakeFiles/7_0.dir/main.cpp.obj"

# External object files for target 7_0
7_0_EXTERNAL_OBJECTS =

7_0.exe: CMakeFiles/7_0.dir/main.cpp.obj
7_0.exe: CMakeFiles/7_0.dir/build.make
7_0.exe: CMakeFiles/7_0.dir/linklibs.rsp
7_0.exe: CMakeFiles/7_0.dir/objects1.rsp
7_0.exe: CMakeFiles/7_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\C language learn\7.0\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 7_0.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\7_0.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/7_0.dir/build: 7_0.exe

.PHONY : CMakeFiles/7_0.dir/build

CMakeFiles/7_0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\7_0.dir\cmake_clean.cmake
.PHONY : CMakeFiles/7_0.dir/clean

CMakeFiles/7_0.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\C language learn\7.0" "D:\C language learn\7.0" "D:\C language learn\7.0\cmake-build-debug" "D:\C language learn\7.0\cmake-build-debug" "D:\C language learn\7.0\cmake-build-debug\CMakeFiles\7_0.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/7_0.dir/depend

