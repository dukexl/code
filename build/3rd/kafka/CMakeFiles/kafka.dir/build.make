# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/xuli/tool/cmake-3.20.0-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/xuli/tool/cmake-3.20.0-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xuli/jzy/learn/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xuli/jzy/learn/code/build

# Include any dependencies generated for this target.
include 3rd/kafka/CMakeFiles/kafka.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include 3rd/kafka/CMakeFiles/kafka.dir/compiler_depend.make

# Include the progress variables for this target.
include 3rd/kafka/CMakeFiles/kafka.dir/progress.make

# Include the compile flags for this target's objects.
include 3rd/kafka/CMakeFiles/kafka.dir/flags.make

3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.o: 3rd/kafka/CMakeFiles/kafka.dir/flags.make
3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.o: ../3rd/kafka/kafkaproducer.cpp
3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.o: 3rd/kafka/CMakeFiles/kafka.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xuli/jzy/learn/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.o"
	cd /home/xuli/jzy/learn/code/build/3rd/kafka && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT 3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.o -MF CMakeFiles/kafka.dir/kafkaproducer.cpp.o.d -o CMakeFiles/kafka.dir/kafkaproducer.cpp.o -c /home/xuli/jzy/learn/code/3rd/kafka/kafkaproducer.cpp

3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kafka.dir/kafkaproducer.cpp.i"
	cd /home/xuli/jzy/learn/code/build/3rd/kafka && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xuli/jzy/learn/code/3rd/kafka/kafkaproducer.cpp > CMakeFiles/kafka.dir/kafkaproducer.cpp.i

3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kafka.dir/kafkaproducer.cpp.s"
	cd /home/xuli/jzy/learn/code/build/3rd/kafka && g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xuli/jzy/learn/code/3rd/kafka/kafkaproducer.cpp -o CMakeFiles/kafka.dir/kafkaproducer.cpp.s

# Object files for target kafka
kafka_OBJECTS = \
"CMakeFiles/kafka.dir/kafkaproducer.cpp.o"

# External object files for target kafka
kafka_EXTERNAL_OBJECTS =

bin/kafka: 3rd/kafka/CMakeFiles/kafka.dir/kafkaproducer.cpp.o
bin/kafka: 3rd/kafka/CMakeFiles/kafka.dir/build.make
bin/kafka: /usr/local/lib64/librdkafka++.so
bin/kafka: 3rd/kafka/CMakeFiles/kafka.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xuli/jzy/learn/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/kafka"
	cd /home/xuli/jzy/learn/code/build/3rd/kafka && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kafka.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
3rd/kafka/CMakeFiles/kafka.dir/build: bin/kafka
.PHONY : 3rd/kafka/CMakeFiles/kafka.dir/build

3rd/kafka/CMakeFiles/kafka.dir/clean:
	cd /home/xuli/jzy/learn/code/build/3rd/kafka && $(CMAKE_COMMAND) -P CMakeFiles/kafka.dir/cmake_clean.cmake
.PHONY : 3rd/kafka/CMakeFiles/kafka.dir/clean

3rd/kafka/CMakeFiles/kafka.dir/depend:
	cd /home/xuli/jzy/learn/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xuli/jzy/learn/code /home/xuli/jzy/learn/code/3rd/kafka /home/xuli/jzy/learn/code/build /home/xuli/jzy/learn/code/build/3rd/kafka /home/xuli/jzy/learn/code/build/3rd/kafka/CMakeFiles/kafka.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 3rd/kafka/CMakeFiles/kafka.dir/depend

