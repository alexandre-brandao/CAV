# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/alexandre/Documents/CAV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexandre/Documents/CAV/build

# Include any dependencies generated for this target.
include CMakeFiles/Readfile.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Readfile.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Readfile.dir/flags.make

CMakeFiles/Readfile.dir/Readfile.cpp.o: CMakeFiles/Readfile.dir/flags.make
CMakeFiles/Readfile.dir/Readfile.cpp.o: ../Readfile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexandre/Documents/CAV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Readfile.dir/Readfile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Readfile.dir/Readfile.cpp.o -c /home/alexandre/Documents/CAV/Readfile.cpp

CMakeFiles/Readfile.dir/Readfile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Readfile.dir/Readfile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexandre/Documents/CAV/Readfile.cpp > CMakeFiles/Readfile.dir/Readfile.cpp.i

CMakeFiles/Readfile.dir/Readfile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Readfile.dir/Readfile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexandre/Documents/CAV/Readfile.cpp -o CMakeFiles/Readfile.dir/Readfile.cpp.s

# Object files for target Readfile
Readfile_OBJECTS = \
"CMakeFiles/Readfile.dir/Readfile.cpp.o"

# External object files for target Readfile
Readfile_EXTERNAL_OBJECTS =

Readfile: CMakeFiles/Readfile.dir/Readfile.cpp.o
Readfile: CMakeFiles/Readfile.dir/build.make
Readfile: /usr/local/lib/libsndfile.a
Readfile: /usr/lib/x86_64-linux-gnu/libvorbisenc.so
Readfile: /usr/lib/x86_64-linux-gnu/libvorbis.so
Readfile: /usr/lib/x86_64-linux-gnu/libFLAC.so
Readfile: /usr/lib/x86_64-linux-gnu/libogg.so
Readfile: /usr/lib/x86_64-linux-gnu/libopus.so
Readfile: CMakeFiles/Readfile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexandre/Documents/CAV/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Readfile"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Readfile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Readfile.dir/build: Readfile

.PHONY : CMakeFiles/Readfile.dir/build

CMakeFiles/Readfile.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Readfile.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Readfile.dir/clean

CMakeFiles/Readfile.dir/depend:
	cd /home/alexandre/Documents/CAV/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexandre/Documents/CAV /home/alexandre/Documents/CAV /home/alexandre/Documents/CAV/build /home/alexandre/Documents/CAV/build /home/alexandre/Documents/CAV/build/CMakeFiles/Readfile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Readfile.dir/depend

