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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab7.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Lab7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab7.dir/flags.make

CMakeFiles/Lab7.dir/main.cpp.o: CMakeFiles/Lab7.dir/flags.make
CMakeFiles/Lab7.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab7.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab7.dir/main.cpp.o -c "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/main.cpp"

CMakeFiles/Lab7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab7.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/main.cpp" > CMakeFiles/Lab7.dir/main.cpp.i

CMakeFiles/Lab7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab7.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/main.cpp" -o CMakeFiles/Lab7.dir/main.cpp.s

CMakeFiles/Lab7.dir/waterHeater.cpp.o: CMakeFiles/Lab7.dir/flags.make
CMakeFiles/Lab7.dir/waterHeater.cpp.o: ../waterHeater.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab7.dir/waterHeater.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab7.dir/waterHeater.cpp.o -c "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/waterHeater.cpp"

CMakeFiles/Lab7.dir/waterHeater.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab7.dir/waterHeater.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/waterHeater.cpp" > CMakeFiles/Lab7.dir/waterHeater.cpp.i

CMakeFiles/Lab7.dir/waterHeater.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab7.dir/waterHeater.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/waterHeater.cpp" -o CMakeFiles/Lab7.dir/waterHeater.cpp.s

CMakeFiles/Lab7.dir/House.cpp.o: CMakeFiles/Lab7.dir/flags.make
CMakeFiles/Lab7.dir/House.cpp.o: ../House.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab7.dir/House.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab7.dir/House.cpp.o -c "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/House.cpp"

CMakeFiles/Lab7.dir/House.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab7.dir/House.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/House.cpp" > CMakeFiles/Lab7.dir/House.cpp.i

CMakeFiles/Lab7.dir/House.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab7.dir/House.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/House.cpp" -o CMakeFiles/Lab7.dir/House.cpp.s

# Object files for target Lab7
Lab7_OBJECTS = \
"CMakeFiles/Lab7.dir/main.cpp.o" \
"CMakeFiles/Lab7.dir/waterHeater.cpp.o" \
"CMakeFiles/Lab7.dir/House.cpp.o"

# External object files for target Lab7
Lab7_EXTERNAL_OBJECTS =

Lab7: CMakeFiles/Lab7.dir/main.cpp.o
Lab7: CMakeFiles/Lab7.dir/waterHeater.cpp.o
Lab7: CMakeFiles/Lab7.dir/House.cpp.o
Lab7: CMakeFiles/Lab7.dir/build.make
Lab7: CMakeFiles/Lab7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Lab7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab7.dir/build: Lab7
.PHONY : CMakeFiles/Lab7.dir/build

CMakeFiles/Lab7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab7.dir/clean

CMakeFiles/Lab7.dir/depend:
	cd "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7" "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7" "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug" "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug" "/mnt/c/Users/defur/OneDrive/School/2021 Fall/CSI 2372 - Advanced Programming Concepts/Lab7/cmake-build-debug/CMakeFiles/Lab7.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab7.dir/depend
