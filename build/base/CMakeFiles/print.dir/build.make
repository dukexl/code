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
include base/CMakeFiles/print.dir/depend.make

# Include the progress variables for this target.
include base/CMakeFiles/print.dir/progress.make

# Include the compile flags for this target's objects.
include base/CMakeFiles/print.dir/flags.make

base/CMakeFiles/print.dir/print.cpp.o: base/CMakeFiles/print.dir/flags.make
base/CMakeFiles/print.dir/print.cpp.o: ../base/print.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/learngit/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object base/CMakeFiles/print.dir/print.cpp.o"
	cd /mnt/hgfs/learngit/code/build/base && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/print.dir/print.cpp.o -c /mnt/hgfs/learngit/code/base/print.cpp

base/CMakeFiles/print.dir/print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/print.dir/print.cpp.i"
	cd /mnt/hgfs/learngit/code/build/base && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/learngit/code/base/print.cpp > CMakeFiles/print.dir/print.cpp.i

base/CMakeFiles/print.dir/print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/print.dir/print.cpp.s"
	cd /mnt/hgfs/learngit/code/build/base && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/learngit/code/base/print.cpp -o CMakeFiles/print.dir/print.cpp.s

# Object files for target print
print_OBJECTS = \
"CMakeFiles/print.dir/print.cpp.o"

# External object files for target print
print_EXTERNAL_OBJECTS =

bin/print: base/CMakeFiles/print.dir/print.cpp.o
bin/print: base/CMakeFiles/print.dir/build.make
bin/print: base/CMakeFiles/print.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/learngit/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/print"
	cd /mnt/hgfs/learngit/code/build/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/print.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
base/CMakeFiles/print.dir/build: bin/print

.PHONY : base/CMakeFiles/print.dir/build

base/CMakeFiles/print.dir/clean:
	cd /mnt/hgfs/learngit/code/build/base && $(CMAKE_COMMAND) -P CMakeFiles/print.dir/cmake_clean.cmake
.PHONY : base/CMakeFiles/print.dir/clean

base/CMakeFiles/print.dir/depend:
	cd /mnt/hgfs/learngit/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/learngit/code /mnt/hgfs/learngit/code/base /mnt/hgfs/learngit/code/build /mnt/hgfs/learngit/code/build/base /mnt/hgfs/learngit/code/build/base/CMakeFiles/print.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : base/CMakeFiles/print.dir/depend
