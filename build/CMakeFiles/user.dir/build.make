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
CMAKE_SOURCE_DIR = /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build

# Include any dependencies generated for this target.
include CMakeFiles/user.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/user.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/user.dir/flags.make

CMakeFiles/user.dir/src/user/user.cpp.o: CMakeFiles/user.dir/flags.make
CMakeFiles/user.dir/src/user/user.cpp.o: ../src/user/user.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/user.dir/src/user/user.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user.dir/src/user/user.cpp.o -c /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/user/user.cpp

CMakeFiles/user.dir/src/user/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user.dir/src/user/user.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/user/user.cpp > CMakeFiles/user.dir/src/user/user.cpp.i

CMakeFiles/user.dir/src/user/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user.dir/src/user/user.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/user/user.cpp -o CMakeFiles/user.dir/src/user/user.cpp.s

CMakeFiles/user.dir/src/database/database.cpp.o: CMakeFiles/user.dir/flags.make
CMakeFiles/user.dir/src/database/database.cpp.o: ../src/database/database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/user.dir/src/database/database.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/user.dir/src/database/database.cpp.o -c /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/database/database.cpp

CMakeFiles/user.dir/src/database/database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/user.dir/src/database/database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/database/database.cpp > CMakeFiles/user.dir/src/database/database.cpp.i

CMakeFiles/user.dir/src/database/database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/user.dir/src/database/database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/src/database/database.cpp -o CMakeFiles/user.dir/src/database/database.cpp.s

# Object files for target user
user_OBJECTS = \
"CMakeFiles/user.dir/src/user/user.cpp.o" \
"CMakeFiles/user.dir/src/database/database.cpp.o"

# External object files for target user
user_EXTERNAL_OBJECTS =

libuser.a: CMakeFiles/user.dir/src/user/user.cpp.o
libuser.a: CMakeFiles/user.dir/src/database/database.cpp.o
libuser.a: CMakeFiles/user.dir/build.make
libuser.a: CMakeFiles/user.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libuser.a"
	$(CMAKE_COMMAND) -P CMakeFiles/user.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/user.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/user.dir/build: libuser.a

.PHONY : CMakeFiles/user.dir/build

CMakeFiles/user.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/user.dir/cmake_clean.cmake
.PHONY : CMakeFiles/user.dir/clean

CMakeFiles/user.dir/depend:
	cd /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build /mnt/c/Users/alkha/OneDrive/Desktop/askfm_project/build/CMakeFiles/user.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/user.dir/depend

