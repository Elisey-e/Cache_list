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
CMAKE_SOURCE_DIR = "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp"

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_function.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_function.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_function.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_function.dir/flags.make

tests/CMakeFiles/test_function.dir/src/test_function.cpp.o: tests/CMakeFiles/test_function.dir/flags.make
tests/CMakeFiles/test_function.dir/src/test_function.cpp.o: ../tests/src/test_function.cpp
tests/CMakeFiles/test_function.dir/src/test_function.cpp.o: tests/CMakeFiles/test_function.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_function.dir/src/test_function.cpp.o"
	cd "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_function.dir/src/test_function.cpp.o -MF CMakeFiles/test_function.dir/src/test_function.cpp.o.d -o CMakeFiles/test_function.dir/src/test_function.cpp.o -c "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tests/src/test_function.cpp"

tests/CMakeFiles/test_function.dir/src/test_function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_function.dir/src/test_function.cpp.i"
	cd "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tests/src/test_function.cpp" > CMakeFiles/test_function.dir/src/test_function.cpp.i

tests/CMakeFiles/test_function.dir/src/test_function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_function.dir/src/test_function.cpp.s"
	cd "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/tests" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tests/src/test_function.cpp" -o CMakeFiles/test_function.dir/src/test_function.cpp.s

# Object files for target test_function
test_function_OBJECTS = \
"CMakeFiles/test_function.dir/src/test_function.cpp.o"

# External object files for target test_function
test_function_EXTERNAL_OBJECTS =

tests/test_function: tests/CMakeFiles/test_function.dir/src/test_function.cpp.o
tests/test_function: tests/CMakeFiles/test_function.dir/build.make
tests/test_function: tests/CMakeFiles/test_function.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_function"
	cd "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_function.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_function.dir/build: tests/test_function
.PHONY : tests/CMakeFiles/test_function.dir/build

tests/CMakeFiles/test_function.dir/clean:
	cd "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/tests" && $(CMAKE_COMMAND) -P CMakeFiles/test_function.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_function.dir/clean

tests/CMakeFiles/test_function.dir/depend:
	cd "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE" "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tests" "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp" "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/tests" "/home/elisey/Рабочий стол/Programming/VLADOS/TASK1_CACHE/tmp/tests/CMakeFiles/test_function.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_function.dir/depend

