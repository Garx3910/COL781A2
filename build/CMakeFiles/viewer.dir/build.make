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
include CMakeFiles/viewer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/viewer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/viewer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/viewer.dir/flags.make

CMakeFiles/viewer.dir/src/hw.cpp.o: CMakeFiles/viewer.dir/flags.make
CMakeFiles/viewer.dir/src/hw.cpp.o: ../src/hw.cpp
CMakeFiles/viewer.dir/src/hw.cpp.o: CMakeFiles/viewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garx/Desktop/COL781/A2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/viewer.dir/src/hw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/viewer.dir/src/hw.cpp.o -MF CMakeFiles/viewer.dir/src/hw.cpp.o.d -o CMakeFiles/viewer.dir/src/hw.cpp.o -c /home/garx/Desktop/COL781/A2/src/hw.cpp

CMakeFiles/viewer.dir/src/hw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viewer.dir/src/hw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/garx/Desktop/COL781/A2/src/hw.cpp > CMakeFiles/viewer.dir/src/hw.cpp.i

CMakeFiles/viewer.dir/src/hw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viewer.dir/src/hw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/garx/Desktop/COL781/A2/src/hw.cpp -o CMakeFiles/viewer.dir/src/hw.cpp.s

CMakeFiles/viewer.dir/src/viewer.cpp.o: CMakeFiles/viewer.dir/flags.make
CMakeFiles/viewer.dir/src/viewer.cpp.o: ../src/viewer.cpp
CMakeFiles/viewer.dir/src/viewer.cpp.o: CMakeFiles/viewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garx/Desktop/COL781/A2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/viewer.dir/src/viewer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/viewer.dir/src/viewer.cpp.o -MF CMakeFiles/viewer.dir/src/viewer.cpp.o.d -o CMakeFiles/viewer.dir/src/viewer.cpp.o -c /home/garx/Desktop/COL781/A2/src/viewer.cpp

CMakeFiles/viewer.dir/src/viewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viewer.dir/src/viewer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/garx/Desktop/COL781/A2/src/viewer.cpp > CMakeFiles/viewer.dir/src/viewer.cpp.i

CMakeFiles/viewer.dir/src/viewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viewer.dir/src/viewer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/garx/Desktop/COL781/A2/src/viewer.cpp -o CMakeFiles/viewer.dir/src/viewer.cpp.s

CMakeFiles/viewer.dir/src/mesh.cpp.o: CMakeFiles/viewer.dir/flags.make
CMakeFiles/viewer.dir/src/mesh.cpp.o: ../src/mesh.cpp
CMakeFiles/viewer.dir/src/mesh.cpp.o: CMakeFiles/viewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garx/Desktop/COL781/A2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/viewer.dir/src/mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/viewer.dir/src/mesh.cpp.o -MF CMakeFiles/viewer.dir/src/mesh.cpp.o.d -o CMakeFiles/viewer.dir/src/mesh.cpp.o -c /home/garx/Desktop/COL781/A2/src/mesh.cpp

CMakeFiles/viewer.dir/src/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viewer.dir/src/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/garx/Desktop/COL781/A2/src/mesh.cpp > CMakeFiles/viewer.dir/src/mesh.cpp.i

CMakeFiles/viewer.dir/src/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viewer.dir/src/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/garx/Desktop/COL781/A2/src/mesh.cpp -o CMakeFiles/viewer.dir/src/mesh.cpp.s

CMakeFiles/viewer.dir/deps/src/gl.c.o: CMakeFiles/viewer.dir/flags.make
CMakeFiles/viewer.dir/deps/src/gl.c.o: ../deps/src/gl.c
CMakeFiles/viewer.dir/deps/src/gl.c.o: CMakeFiles/viewer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/garx/Desktop/COL781/A2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/viewer.dir/deps/src/gl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/viewer.dir/deps/src/gl.c.o -MF CMakeFiles/viewer.dir/deps/src/gl.c.o.d -o CMakeFiles/viewer.dir/deps/src/gl.c.o -c /home/garx/Desktop/COL781/A2/deps/src/gl.c

CMakeFiles/viewer.dir/deps/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/viewer.dir/deps/src/gl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/garx/Desktop/COL781/A2/deps/src/gl.c > CMakeFiles/viewer.dir/deps/src/gl.c.i

CMakeFiles/viewer.dir/deps/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/viewer.dir/deps/src/gl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/garx/Desktop/COL781/A2/deps/src/gl.c -o CMakeFiles/viewer.dir/deps/src/gl.c.s

# Object files for target viewer
viewer_OBJECTS = \
"CMakeFiles/viewer.dir/src/hw.cpp.o" \
"CMakeFiles/viewer.dir/src/viewer.cpp.o" \
"CMakeFiles/viewer.dir/src/mesh.cpp.o" \
"CMakeFiles/viewer.dir/deps/src/gl.c.o"

# External object files for target viewer
viewer_EXTERNAL_OBJECTS =

libviewer.a: CMakeFiles/viewer.dir/src/hw.cpp.o
libviewer.a: CMakeFiles/viewer.dir/src/viewer.cpp.o
libviewer.a: CMakeFiles/viewer.dir/src/mesh.cpp.o
libviewer.a: CMakeFiles/viewer.dir/deps/src/gl.c.o
libviewer.a: CMakeFiles/viewer.dir/build.make
libviewer.a: CMakeFiles/viewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/garx/Desktop/COL781/A2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libviewer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/viewer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/viewer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/viewer.dir/build: libviewer.a
.PHONY : CMakeFiles/viewer.dir/build

CMakeFiles/viewer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/viewer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/viewer.dir/clean

CMakeFiles/viewer.dir/depend:
	cd /home/garx/Desktop/COL781/A2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/garx/Desktop/COL781/A2 /home/garx/Desktop/COL781/A2 /home/garx/Desktop/COL781/A2/build /home/garx/Desktop/COL781/A2/build /home/garx/Desktop/COL781/A2/build/CMakeFiles/viewer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/viewer.dir/depend

