# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/xuli/build/cmake-3.17.1-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/xuli/build/cmake-3.17.1-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/hgfs/learngit/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/learngit/code/build

# Include any dependencies generated for this target.
include base/CMakeFiles/codestyle.dir/depend.make

# Include the progress variables for this target.
include base/CMakeFiles/codestyle.dir/progress.make

# Include the compile flags for this target's objects.
include base/CMakeFiles/codestyle.dir/flags.make

base/CMakeFiles/codestyle.dir/codestyle.cpp.o: base/CMakeFiles/codestyle.dir/flags.make
base/CMakeFiles/codestyle.dir/codestyle.cpp.o: ../base/codestyle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/learngit/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/CMakeFiles/codestyle.dir/codestyle.cpp.o"
	cd /mnt/hgfs/learngit/code/build/base && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/codestyle.dir/codestyle.cpp.o -c /mnt/hgfs/learngit/code/base/codestyle.cpp

base/CMakeFiles/codestyle.dir/codestyle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codestyle.dir/codestyle.cpp.i"
	cd /mnt/hgfs/learngit/code/build/base && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/learngit/code/base/codestyle.cpp > CMakeFiles/codestyle.dir/codestyle.cpp.i

base/CMakeFiles/codestyle.dir/codestyle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codestyle.dir/codestyle.cpp.s"
	cd /mnt/hgfs/learngit/code/build/base && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/learngit/code/base/codestyle.cpp -o CMakeFiles/codestyle.dir/codestyle.cpp.s

# Object files for target codestyle
codestyle_OBJECTS = \
"CMakeFiles/codestyle.dir/codestyle.cpp.o"

# External object files for target codestyle
codestyle_EXTERNAL_OBJECTS =

bin/codestyle: base/CMakeFiles/codestyle.dir/codestyle.cpp.o
bin/codestyle: base/CMakeFiles/codestyle.dir/build.make
bin/codestyle: base/CMakeFiles/codestyle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/learngit/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/codestyle"
	cd /mnt/hgfs/learngit/code/build/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codestyle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/CMakeFiles/codestyle.dir/build: bin/codestyle

.PHONY : base/CMakeFiles/codestyle.dir/build

base/CMakeFiles/codestyle.dir/clean:
	cd /mnt/hgfs/learngit/code/build/base && $(CMAKE_COMMAND) -P CMakeFiles/codestyle.dir/cmake_clean.cmake
.PHONY : base/CMakeFiles/codestyle.dir/clean

base/CMakeFiles/codestyle.dir/depend:
	cd /mnt/hgfs/learngit/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/learngit/code /mnt/hgfs/learngit/code/base /mnt/hgfs/learngit/code/build /mnt/hgfs/learngit/code/build/base /mnt/hgfs/learngit/code/build/base/CMakeFiles/codestyle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/CMakeFiles/codestyle.dir/depend

