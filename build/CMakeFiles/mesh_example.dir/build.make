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
CMAKE_SOURCE_DIR = /home/garx/Desktop/COL781/A2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/garx/Desktop/COL781/A2/build

# Include any dependencies generated for this target.
include CMakeFiles/mesh_example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mesh_example.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mesh_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mesh_example.dir/flags.make

CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o: CMakeFiles/mesh_example.dir/flags.make
CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o: ../src/mesh_example.cpp
CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o: CMakeFiles/mesh_example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garx/Desktop/COL781/A2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o -MF CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o.d -o CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o -c /home/garx/Desktop/COL781/A2/src/mesh_example.cpp

CMakeFiles/mesh_example.dir/src/mesh_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mesh_example.dir/src/mesh_example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/garx/Desktop/COL781/A2/src/mesh_example.cpp > CMakeFiles/mesh_example.dir/src/mesh_example.cpp.i

CMakeFiles/mesh_example.dir/src/mesh_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mesh_example.dir/src/mesh_example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/garx/Desktop/COL781/A2/src/mesh_example.cpp -o CMakeFiles/mesh_example.dir/src/mesh_example.cpp.s

# Object files for target mesh_example
mesh_example_OBJECTS = \
"CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o"

# External object files for target mesh_example
mesh_example_EXTERNAL_OBJECTS =

mesh_example: CMakeFiles/mesh_example.dir/src/mesh_example.cpp.o
mesh_example: CMakeFiles/mesh_example.dir/build.make
mesh_example: libviewer.a
mesh_example: /usr/lib/x86_64-linux-gnu/libGL.so
mesh_example: /usr/lib/x86_64-linux-gnu/libSDL2.so
mesh_example: CMakeFiles/mesh_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/garx/Desktop/COL781/A2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mesh_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mesh_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mesh_example.dir/build: mesh_example
.PHONY : CMakeFiles/mesh_example.dir/build

CMakeFiles/mesh_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mesh_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mesh_example.dir/clean

CMakeFiles/mesh_example.dir/depend:
	cd /home/garx/Desktop/COL781/A2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/garx/Desktop/COL781/A2 /home/garx/Desktop/COL781/A2 /home/garx/Desktop/COL781/A2/build /home/garx/Desktop/COL781/A2/build /home/garx/Desktop/COL781/A2/build/CMakeFiles/mesh_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mesh_example.dir/depend

