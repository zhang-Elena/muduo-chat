# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elena/桌面/elena/muduo_chat/testmuduo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elena/桌面/elena/muduo_chat/testmuduo/build

# Include any dependencies generated for this target.
include CMakeFiles/chat_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chat_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chat_server.dir/flags.make

CMakeFiles/chat_server.dir/muduo_server.cpp.o: CMakeFiles/chat_server.dir/flags.make
CMakeFiles/chat_server.dir/muduo_server.cpp.o: ../muduo_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/elena/桌面/elena/muduo_chat/testmuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chat_server.dir/muduo_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chat_server.dir/muduo_server.cpp.o -c /home/elena/桌面/elena/muduo_chat/testmuduo/muduo_server.cpp

CMakeFiles/chat_server.dir/muduo_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chat_server.dir/muduo_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elena/桌面/elena/muduo_chat/testmuduo/muduo_server.cpp > CMakeFiles/chat_server.dir/muduo_server.cpp.i

CMakeFiles/chat_server.dir/muduo_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chat_server.dir/muduo_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elena/桌面/elena/muduo_chat/testmuduo/muduo_server.cpp -o CMakeFiles/chat_server.dir/muduo_server.cpp.s

# Object files for target chat_server
chat_server_OBJECTS = \
"CMakeFiles/chat_server.dir/muduo_server.cpp.o"

# External object files for target chat_server
chat_server_EXTERNAL_OBJECTS =

chat_server: CMakeFiles/chat_server.dir/muduo_server.cpp.o
chat_server: CMakeFiles/chat_server.dir/build.make
chat_server: CMakeFiles/chat_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/elena/桌面/elena/muduo_chat/testmuduo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chat_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chat_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chat_server.dir/build: chat_server

.PHONY : CMakeFiles/chat_server.dir/build

CMakeFiles/chat_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chat_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chat_server.dir/clean

CMakeFiles/chat_server.dir/depend:
	cd /home/elena/桌面/elena/muduo_chat/testmuduo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elena/桌面/elena/muduo_chat/testmuduo /home/elena/桌面/elena/muduo_chat/testmuduo /home/elena/桌面/elena/muduo_chat/testmuduo/build /home/elena/桌面/elena/muduo_chat/testmuduo/build /home/elena/桌面/elena/muduo_chat/testmuduo/build/CMakeFiles/chat_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chat_server.dir/depend

