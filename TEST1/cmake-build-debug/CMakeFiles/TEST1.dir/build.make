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
CMAKE_SOURCE_DIR = "D:\C language learn\TEST1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\C language learn\TEST1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TEST1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TEST1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TEST1.dir/flags.make

CMakeFiles/TEST1.dir/main.cpp.obj: CMakeFiles/TEST1.dir/flags.make
CMakeFiles/TEST1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\C language learn\TEST1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TEST1.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TEST1.dir\main.cpp.obj -c "D:\C language learn\TEST1\main.cpp"

CMakeFiles/TEST1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEST1.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\C language learn\TEST1\main.cpp" > CMakeFiles\TEST1.dir\main.cpp.i

CMakeFiles/TEST1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEST1.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\C language learn\TEST1\main.cpp" -o CMakeFiles\TEST1.dir\main.cpp.s

# Object files for target TEST1
TEST1_OBJECTS = \
"CMakeFiles/TEST1.dir/main.cpp.obj"

# External object files for target TEST1
TEST1_EXTERNAL_OBJECTS =

TEST1.exe: CMakeFiles/TEST1.dir/main.cpp.obj
TEST1.exe: CMakeFiles/TEST1.dir/build.make
TEST1.exe: CMakeFiles/TEST1.dir/linklibs.rsp
TEST1.exe: CMakeFiles/TEST1.dir/objects1.rsp
TEST1.exe: CMakeFiles/TEST1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\C language learn\TEST1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TEST1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TEST1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TEST1.dir/build: TEST1.exe

.PHONY : CMakeFiles/TEST1.dir/build

CMakeFiles/TEST1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TEST1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TEST1.dir/clean

CMakeFiles/TEST1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\C language learn\TEST1" "D:\C language learn\TEST1" "D:\C language learn\TEST1\cmake-build-debug" "D:\C language learn\TEST1\cmake-build-debug" "D:\C language learn\TEST1\cmake-build-debug\CMakeFiles\TEST1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TEST1.dir/depend

