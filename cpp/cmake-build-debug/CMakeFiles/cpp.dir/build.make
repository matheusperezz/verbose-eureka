# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Matheus\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Matheus\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Matheus\Documents\Code\verbose-eureka\cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp.dir/flags.make

CMakeFiles/cpp.dir/main.cpp.obj: CMakeFiles/cpp.dir/flags.make
CMakeFiles/cpp.dir/main.cpp.obj: C:/Users/Matheus/Documents/Code/verbose-eureka/cpp/main.cpp
CMakeFiles/cpp.dir/main.cpp.obj: CMakeFiles/cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp.dir/main.cpp.obj"
	C:\Users\Matheus\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpp.dir/main.cpp.obj -MF CMakeFiles\cpp.dir\main.cpp.obj.d -o CMakeFiles\cpp.dir\main.cpp.obj -c C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\main.cpp

CMakeFiles/cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp.dir/main.cpp.i"
	C:\Users\Matheus\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\main.cpp > CMakeFiles\cpp.dir\main.cpp.i

CMakeFiles/cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp.dir/main.cpp.s"
	C:\Users\Matheus\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\main.cpp -o CMakeFiles\cpp.dir\main.cpp.s

CMakeFiles/cpp.dir/leetcode.cpp.obj: CMakeFiles/cpp.dir/flags.make
CMakeFiles/cpp.dir/leetcode.cpp.obj: C:/Users/Matheus/Documents/Code/verbose-eureka/cpp/leetcode.cpp
CMakeFiles/cpp.dir/leetcode.cpp.obj: CMakeFiles/cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpp.dir/leetcode.cpp.obj"
	C:\Users\Matheus\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpp.dir/leetcode.cpp.obj -MF CMakeFiles\cpp.dir\leetcode.cpp.obj.d -o CMakeFiles\cpp.dir\leetcode.cpp.obj -c C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\leetcode.cpp

CMakeFiles/cpp.dir/leetcode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp.dir/leetcode.cpp.i"
	C:\Users\Matheus\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\leetcode.cpp > CMakeFiles\cpp.dir\leetcode.cpp.i

CMakeFiles/cpp.dir/leetcode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp.dir/leetcode.cpp.s"
	C:\Users\Matheus\AppData\Local\Programs\CLion\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\leetcode.cpp -o CMakeFiles\cpp.dir\leetcode.cpp.s

# Object files for target cpp
cpp_OBJECTS = \
"CMakeFiles/cpp.dir/main.cpp.obj" \
"CMakeFiles/cpp.dir/leetcode.cpp.obj"

# External object files for target cpp
cpp_EXTERNAL_OBJECTS =

cpp.exe: CMakeFiles/cpp.dir/main.cpp.obj
cpp.exe: CMakeFiles/cpp.dir/leetcode.cpp.obj
cpp.exe: CMakeFiles/cpp.dir/build.make
cpp.exe: CMakeFiles/cpp.dir/linkLibs.rsp
cpp.exe: CMakeFiles/cpp.dir/objects1.rsp
cpp.exe: CMakeFiles/cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cpp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp.dir/build: cpp.exe
.PHONY : CMakeFiles/cpp.dir/build

CMakeFiles/cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cpp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cpp.dir/clean

CMakeFiles/cpp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Matheus\Documents\Code\verbose-eureka\cpp C:\Users\Matheus\Documents\Code\verbose-eureka\cpp C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\cmake-build-debug C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\cmake-build-debug C:\Users\Matheus\Documents\Code\verbose-eureka\cpp\cmake-build-debug\CMakeFiles\cpp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp.dir/depend

