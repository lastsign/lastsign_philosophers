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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ptycho/Documents/42cursus/lastsign_philosophers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_three.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_three.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_three.dir/flags.make

CMakeFiles/philo_three.dir/philo_three/philo_three.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/philo_three.c.o: ../philo_three/philo_three.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_three.dir/philo_three/philo_three.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/philo_three.c.o   -c /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/philo_three.c

CMakeFiles/philo_three.dir/philo_three/philo_three.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/philo_three.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/philo_three.c > CMakeFiles/philo_three.dir/philo_three/philo_three.c.i

CMakeFiles/philo_three.dir/philo_three/philo_three.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/philo_three.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/philo_three.c -o CMakeFiles/philo_three.dir/philo_three/philo_three.c.s

CMakeFiles/philo_three.dir/philo_three/utils.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/utils.c.o: ../philo_three/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo_three.dir/philo_three/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/utils.c.o   -c /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/utils.c

CMakeFiles/philo_three.dir/philo_three/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/utils.c > CMakeFiles/philo_three.dir/philo_three/utils.c.i

CMakeFiles/philo_three.dir/philo_three/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/utils.c -o CMakeFiles/philo_three.dir/philo_three/utils.c.s

CMakeFiles/philo_three.dir/philo_three/utils_libft.c.o: CMakeFiles/philo_three.dir/flags.make
CMakeFiles/philo_three.dir/philo_three/utils_libft.c.o: ../philo_three/utils_libft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo_three.dir/philo_three/utils_libft.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_three.dir/philo_three/utils_libft.c.o   -c /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/utils_libft.c

CMakeFiles/philo_three.dir/philo_three/utils_libft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_three.dir/philo_three/utils_libft.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/utils_libft.c > CMakeFiles/philo_three.dir/philo_three/utils_libft.c.i

CMakeFiles/philo_three.dir/philo_three/utils_libft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_three.dir/philo_three/utils_libft.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ptycho/Documents/42cursus/lastsign_philosophers/philo_three/utils_libft.c -o CMakeFiles/philo_three.dir/philo_three/utils_libft.c.s

# Object files for target philo_three
philo_three_OBJECTS = \
"CMakeFiles/philo_three.dir/philo_three/philo_three.c.o" \
"CMakeFiles/philo_three.dir/philo_three/utils.c.o" \
"CMakeFiles/philo_three.dir/philo_three/utils_libft.c.o"

# External object files for target philo_three
philo_three_EXTERNAL_OBJECTS =

philo_three: CMakeFiles/philo_three.dir/philo_three/philo_three.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/utils.c.o
philo_three: CMakeFiles/philo_three.dir/philo_three/utils_libft.c.o
philo_three: CMakeFiles/philo_three.dir/build.make
philo_three: CMakeFiles/philo_three.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable philo_three"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_three.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_three.dir/build: philo_three

.PHONY : CMakeFiles/philo_three.dir/build

CMakeFiles/philo_three.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_three.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_three.dir/clean

CMakeFiles/philo_three.dir/depend:
	cd /Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ptycho/Documents/42cursus/lastsign_philosophers /Users/ptycho/Documents/42cursus/lastsign_philosophers /Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug /Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug /Users/ptycho/Documents/42cursus/lastsign_philosophers/cmake-build-debug/CMakeFiles/philo_three.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_three.dir/depend

