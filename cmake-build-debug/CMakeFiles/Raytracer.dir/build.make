# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/tessa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tessa/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tessa/CLionProjects/Raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tessa/CLionProjects/Raytracer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Raytracer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Raytracer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Raytracer.dir/flags.make

CMakeFiles/Raytracer.dir/main.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Raytracer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/main.cpp.o -c /home/tessa/CLionProjects/Raytracer/main.cpp

CMakeFiles/Raytracer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/main.cpp > CMakeFiles/Raytracer.dir/main.cpp.i

CMakeFiles/Raytracer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/main.cpp -o CMakeFiles/Raytracer.dir/main.cpp.s

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.o: ../Helpers/Vectors/Vector2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.o -c /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector2.cpp

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector2.cpp > CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.i

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector2.cpp -o CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.s

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.o: ../Helpers/Vectors/Vector3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.o -c /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector3.cpp

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector3.cpp > CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.i

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector3.cpp -o CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.s

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.o: ../Helpers/Vectors/Vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.o -c /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector.cpp

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector.cpp > CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.i

CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/Vector.cpp -o CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.s

CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.o: ../Helpers/Vectors/hvector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.o -c /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/hvector.cpp

CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/hvector.cpp > CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.i

CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/Helpers/Vectors/hvector.cpp -o CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.s

CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.o: ../Helpers/Matrices/transform.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.o -c /home/tessa/CLionProjects/Raytracer/Helpers/Matrices/transform.cpp

CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/Helpers/Matrices/transform.cpp > CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.i

CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/Helpers/Matrices/transform.cpp -o CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.s

CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.o: ../Helpers/rgb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.o -c /home/tessa/CLionProjects/Raytracer/Helpers/rgb.cpp

CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/Helpers/rgb.cpp > CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.i

CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/Helpers/rgb.cpp -o CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.s

CMakeFiles/Raytracer.dir/Helpers/image.cpp.o: CMakeFiles/Raytracer.dir/flags.make
CMakeFiles/Raytracer.dir/Helpers/image.cpp.o: ../Helpers/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Raytracer.dir/Helpers/image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Raytracer.dir/Helpers/image.cpp.o -c /home/tessa/CLionProjects/Raytracer/Helpers/image.cpp

CMakeFiles/Raytracer.dir/Helpers/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Raytracer.dir/Helpers/image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tessa/CLionProjects/Raytracer/Helpers/image.cpp > CMakeFiles/Raytracer.dir/Helpers/image.cpp.i

CMakeFiles/Raytracer.dir/Helpers/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Raytracer.dir/Helpers/image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tessa/CLionProjects/Raytracer/Helpers/image.cpp -o CMakeFiles/Raytracer.dir/Helpers/image.cpp.s

# Object files for target Raytracer
Raytracer_OBJECTS = \
"CMakeFiles/Raytracer.dir/main.cpp.o" \
"CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.o" \
"CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.o" \
"CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.o" \
"CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.o" \
"CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.o" \
"CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.o" \
"CMakeFiles/Raytracer.dir/Helpers/image.cpp.o"

# External object files for target Raytracer
Raytracer_EXTERNAL_OBJECTS =

Raytracer: CMakeFiles/Raytracer.dir/main.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector2.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector3.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/Helpers/Vectors/Vector.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/Helpers/Vectors/hvector.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/Helpers/Matrices/transform.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/Helpers/rgb.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/Helpers/image.cpp.o
Raytracer: CMakeFiles/Raytracer.dir/build.make
Raytracer: CMakeFiles/Raytracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Raytracer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Raytracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Raytracer.dir/build: Raytracer

.PHONY : CMakeFiles/Raytracer.dir/build

CMakeFiles/Raytracer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Raytracer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Raytracer.dir/clean

CMakeFiles/Raytracer.dir/depend:
	cd /home/tessa/CLionProjects/Raytracer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tessa/CLionProjects/Raytracer /home/tessa/CLionProjects/Raytracer /home/tessa/CLionProjects/Raytracer/cmake-build-debug /home/tessa/CLionProjects/Raytracer/cmake-build-debug /home/tessa/CLionProjects/Raytracer/cmake-build-debug/CMakeFiles/Raytracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Raytracer.dir/depend

