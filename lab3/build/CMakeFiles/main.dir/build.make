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
CMAKE_SOURCE_DIR = /home/ananas/Desktop/programs/OOP_Labs/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ananas/Desktop/programs/OOP_Labs/lab3/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: ../main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/ananas/Desktop/programs/OOP_Labs/lab3/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ananas/Desktop/programs/OOP_Labs/lab3/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ananas/Desktop/programs/OOP_Labs/lab3/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/src/point.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/point.cpp.o: ../src/point.cpp
CMakeFiles/main.dir/src/point.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/point.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/point.cpp.o -MF CMakeFiles/main.dir/src/point.cpp.o.d -o CMakeFiles/main.dir/src/point.cpp.o -c /home/ananas/Desktop/programs/OOP_Labs/lab3/src/point.cpp

CMakeFiles/main.dir/src/point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ananas/Desktop/programs/OOP_Labs/lab3/src/point.cpp > CMakeFiles/main.dir/src/point.cpp.i

CMakeFiles/main.dir/src/point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ananas/Desktop/programs/OOP_Labs/lab3/src/point.cpp -o CMakeFiles/main.dir/src/point.cpp.s

CMakeFiles/main.dir/src/figure.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/figure.cpp.o: ../src/figure.cpp
CMakeFiles/main.dir/src/figure.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/figure.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/figure.cpp.o -MF CMakeFiles/main.dir/src/figure.cpp.o.d -o CMakeFiles/main.dir/src/figure.cpp.o -c /home/ananas/Desktop/programs/OOP_Labs/lab3/src/figure.cpp

CMakeFiles/main.dir/src/figure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/figure.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ananas/Desktop/programs/OOP_Labs/lab3/src/figure.cpp > CMakeFiles/main.dir/src/figure.cpp.i

CMakeFiles/main.dir/src/figure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/figure.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ananas/Desktop/programs/OOP_Labs/lab3/src/figure.cpp -o CMakeFiles/main.dir/src/figure.cpp.s

CMakeFiles/main.dir/src/Trapeze.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Trapeze.cpp.o: ../src/Trapeze.cpp
CMakeFiles/main.dir/src/Trapeze.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/Trapeze.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/Trapeze.cpp.o -MF CMakeFiles/main.dir/src/Trapeze.cpp.o.d -o CMakeFiles/main.dir/src/Trapeze.cpp.o -c /home/ananas/Desktop/programs/OOP_Labs/lab3/src/Trapeze.cpp

CMakeFiles/main.dir/src/Trapeze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Trapeze.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ananas/Desktop/programs/OOP_Labs/lab3/src/Trapeze.cpp > CMakeFiles/main.dir/src/Trapeze.cpp.i

CMakeFiles/main.dir/src/Trapeze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Trapeze.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ananas/Desktop/programs/OOP_Labs/lab3/src/Trapeze.cpp -o CMakeFiles/main.dir/src/Trapeze.cpp.s

CMakeFiles/main.dir/src/rectangle.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/rectangle.cpp.o: ../src/rectangle.cpp
CMakeFiles/main.dir/src/rectangle.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/rectangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/rectangle.cpp.o -MF CMakeFiles/main.dir/src/rectangle.cpp.o.d -o CMakeFiles/main.dir/src/rectangle.cpp.o -c /home/ananas/Desktop/programs/OOP_Labs/lab3/src/rectangle.cpp

CMakeFiles/main.dir/src/rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/rectangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ananas/Desktop/programs/OOP_Labs/lab3/src/rectangle.cpp > CMakeFiles/main.dir/src/rectangle.cpp.i

CMakeFiles/main.dir/src/rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/rectangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ananas/Desktop/programs/OOP_Labs/lab3/src/rectangle.cpp -o CMakeFiles/main.dir/src/rectangle.cpp.s

CMakeFiles/main.dir/src/square.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/square.cpp.o: ../src/square.cpp
CMakeFiles/main.dir/src/square.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/square.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/square.cpp.o -MF CMakeFiles/main.dir/src/square.cpp.o.d -o CMakeFiles/main.dir/src/square.cpp.o -c /home/ananas/Desktop/programs/OOP_Labs/lab3/src/square.cpp

CMakeFiles/main.dir/src/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/square.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ananas/Desktop/programs/OOP_Labs/lab3/src/square.cpp > CMakeFiles/main.dir/src/square.cpp.i

CMakeFiles/main.dir/src/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/square.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ananas/Desktop/programs/OOP_Labs/lab3/src/square.cpp -o CMakeFiles/main.dir/src/square.cpp.s

CMakeFiles/main.dir/src/array.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/array.cpp.o: ../src/array.cpp
CMakeFiles/main.dir/src/array.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/array.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/array.cpp.o -MF CMakeFiles/main.dir/src/array.cpp.o.d -o CMakeFiles/main.dir/src/array.cpp.o -c /home/ananas/Desktop/programs/OOP_Labs/lab3/src/array.cpp

CMakeFiles/main.dir/src/array.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/array.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ananas/Desktop/programs/OOP_Labs/lab3/src/array.cpp > CMakeFiles/main.dir/src/array.cpp.i

CMakeFiles/main.dir/src/array.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/array.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ananas/Desktop/programs/OOP_Labs/lab3/src/array.cpp -o CMakeFiles/main.dir/src/array.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/src/point.cpp.o" \
"CMakeFiles/main.dir/src/figure.cpp.o" \
"CMakeFiles/main.dir/src/Trapeze.cpp.o" \
"CMakeFiles/main.dir/src/rectangle.cpp.o" \
"CMakeFiles/main.dir/src/square.cpp.o" \
"CMakeFiles/main.dir/src/array.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/src/point.cpp.o
main: CMakeFiles/main.dir/src/figure.cpp.o
main: CMakeFiles/main.dir/src/Trapeze.cpp.o
main: CMakeFiles/main.dir/src/rectangle.cpp.o
main: CMakeFiles/main.dir/src/square.cpp.o
main: CMakeFiles/main.dir/src/array.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/ananas/Desktop/programs/OOP_Labs/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ananas/Desktop/programs/OOP_Labs/lab3 /home/ananas/Desktop/programs/OOP_Labs/lab3 /home/ananas/Desktop/programs/OOP_Labs/lab3/build /home/ananas/Desktop/programs/OOP_Labs/lab3/build /home/ananas/Desktop/programs/OOP_Labs/lab3/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
