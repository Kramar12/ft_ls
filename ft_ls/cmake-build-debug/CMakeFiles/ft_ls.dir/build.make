# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ariabyi/CLionProjects/ft_ls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ft_ls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ft_ls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ft_ls.dir/flags.make

CMakeFiles/ft_ls.dir/ft_ls.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/ft_ls.c.o: ../ft_ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ft_ls.dir/ft_ls.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/ft_ls.c.o   -c /Users/ariabyi/CLionProjects/ft_ls/ft_ls.c

CMakeFiles/ft_ls.dir/ft_ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/ft_ls.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ariabyi/CLionProjects/ft_ls/ft_ls.c > CMakeFiles/ft_ls.dir/ft_ls.c.i

CMakeFiles/ft_ls.dir/ft_ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/ft_ls.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ariabyi/CLionProjects/ft_ls/ft_ls.c -o CMakeFiles/ft_ls.dir/ft_ls.c.s

CMakeFiles/ft_ls.dir/ft_ls.c.o.requires:

.PHONY : CMakeFiles/ft_ls.dir/ft_ls.c.o.requires

CMakeFiles/ft_ls.dir/ft_ls.c.o.provides: CMakeFiles/ft_ls.dir/ft_ls.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ls.dir/build.make CMakeFiles/ft_ls.dir/ft_ls.c.o.provides.build
.PHONY : CMakeFiles/ft_ls.dir/ft_ls.c.o.provides

CMakeFiles/ft_ls.dir/ft_ls.c.o.provides.build: CMakeFiles/ft_ls.dir/ft_ls.c.o


CMakeFiles/ft_ls.dir/major.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/major.c.o: ../major.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ft_ls.dir/major.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/major.c.o   -c /Users/ariabyi/CLionProjects/ft_ls/major.c

CMakeFiles/ft_ls.dir/major.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/major.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ariabyi/CLionProjects/ft_ls/major.c > CMakeFiles/ft_ls.dir/major.c.i

CMakeFiles/ft_ls.dir/major.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/major.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ariabyi/CLionProjects/ft_ls/major.c -o CMakeFiles/ft_ls.dir/major.c.s

CMakeFiles/ft_ls.dir/major.c.o.requires:

.PHONY : CMakeFiles/ft_ls.dir/major.c.o.requires

CMakeFiles/ft_ls.dir/major.c.o.provides: CMakeFiles/ft_ls.dir/major.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ls.dir/build.make CMakeFiles/ft_ls.dir/major.c.o.provides.build
.PHONY : CMakeFiles/ft_ls.dir/major.c.o.provides

CMakeFiles/ft_ls.dir/major.c.o.provides.build: CMakeFiles/ft_ls.dir/major.c.o


CMakeFiles/ft_ls.dir/main.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ft_ls.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/main.c.o   -c /Users/ariabyi/CLionProjects/ft_ls/main.c

CMakeFiles/ft_ls.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ariabyi/CLionProjects/ft_ls/main.c > CMakeFiles/ft_ls.dir/main.c.i

CMakeFiles/ft_ls.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ariabyi/CLionProjects/ft_ls/main.c -o CMakeFiles/ft_ls.dir/main.c.s

CMakeFiles/ft_ls.dir/main.c.o.requires:

.PHONY : CMakeFiles/ft_ls.dir/main.c.o.requires

CMakeFiles/ft_ls.dir/main.c.o.provides: CMakeFiles/ft_ls.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ls.dir/build.make CMakeFiles/ft_ls.dir/main.c.o.provides.build
.PHONY : CMakeFiles/ft_ls.dir/main.c.o.provides

CMakeFiles/ft_ls.dir/main.c.o.provides.build: CMakeFiles/ft_ls.dir/main.c.o


CMakeFiles/ft_ls.dir/mauxiliary.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/mauxiliary.c.o: ../mauxiliary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ft_ls.dir/mauxiliary.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/mauxiliary.c.o   -c /Users/ariabyi/CLionProjects/ft_ls/mauxiliary.c

CMakeFiles/ft_ls.dir/mauxiliary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/mauxiliary.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ariabyi/CLionProjects/ft_ls/mauxiliary.c > CMakeFiles/ft_ls.dir/mauxiliary.c.i

CMakeFiles/ft_ls.dir/mauxiliary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/mauxiliary.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ariabyi/CLionProjects/ft_ls/mauxiliary.c -o CMakeFiles/ft_ls.dir/mauxiliary.c.s

CMakeFiles/ft_ls.dir/mauxiliary.c.o.requires:

.PHONY : CMakeFiles/ft_ls.dir/mauxiliary.c.o.requires

CMakeFiles/ft_ls.dir/mauxiliary.c.o.provides: CMakeFiles/ft_ls.dir/mauxiliary.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ls.dir/build.make CMakeFiles/ft_ls.dir/mauxiliary.c.o.provides.build
.PHONY : CMakeFiles/ft_ls.dir/mauxiliary.c.o.provides

CMakeFiles/ft_ls.dir/mauxiliary.c.o.provides.build: CMakeFiles/ft_ls.dir/mauxiliary.c.o


CMakeFiles/ft_ls.dir/rightstypes.c.o: CMakeFiles/ft_ls.dir/flags.make
CMakeFiles/ft_ls.dir/rightstypes.c.o: ../rightstypes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ft_ls.dir/rightstypes.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_ls.dir/rightstypes.c.o   -c /Users/ariabyi/CLionProjects/ft_ls/rightstypes.c

CMakeFiles/ft_ls.dir/rightstypes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_ls.dir/rightstypes.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ariabyi/CLionProjects/ft_ls/rightstypes.c > CMakeFiles/ft_ls.dir/rightstypes.c.i

CMakeFiles/ft_ls.dir/rightstypes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_ls.dir/rightstypes.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ariabyi/CLionProjects/ft_ls/rightstypes.c -o CMakeFiles/ft_ls.dir/rightstypes.c.s

CMakeFiles/ft_ls.dir/rightstypes.c.o.requires:

.PHONY : CMakeFiles/ft_ls.dir/rightstypes.c.o.requires

CMakeFiles/ft_ls.dir/rightstypes.c.o.provides: CMakeFiles/ft_ls.dir/rightstypes.c.o.requires
	$(MAKE) -f CMakeFiles/ft_ls.dir/build.make CMakeFiles/ft_ls.dir/rightstypes.c.o.provides.build
.PHONY : CMakeFiles/ft_ls.dir/rightstypes.c.o.provides

CMakeFiles/ft_ls.dir/rightstypes.c.o.provides.build: CMakeFiles/ft_ls.dir/rightstypes.c.o


# Object files for target ft_ls
ft_ls_OBJECTS = \
"CMakeFiles/ft_ls.dir/ft_ls.c.o" \
"CMakeFiles/ft_ls.dir/major.c.o" \
"CMakeFiles/ft_ls.dir/main.c.o" \
"CMakeFiles/ft_ls.dir/mauxiliary.c.o" \
"CMakeFiles/ft_ls.dir/rightstypes.c.o"

# External object files for target ft_ls
ft_ls_EXTERNAL_OBJECTS =

ft_ls: CMakeFiles/ft_ls.dir/ft_ls.c.o
ft_ls: CMakeFiles/ft_ls.dir/major.c.o
ft_ls: CMakeFiles/ft_ls.dir/main.c.o
ft_ls: CMakeFiles/ft_ls.dir/mauxiliary.c.o
ft_ls: CMakeFiles/ft_ls.dir/rightstypes.c.o
ft_ls: CMakeFiles/ft_ls.dir/build.make
ft_ls: ../libft/libft.a
ft_ls: ../ft_printf/libftprintf.a
ft_ls: CMakeFiles/ft_ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ft_ls"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ft_ls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ft_ls.dir/build: ft_ls

.PHONY : CMakeFiles/ft_ls.dir/build

CMakeFiles/ft_ls.dir/requires: CMakeFiles/ft_ls.dir/ft_ls.c.o.requires
CMakeFiles/ft_ls.dir/requires: CMakeFiles/ft_ls.dir/major.c.o.requires
CMakeFiles/ft_ls.dir/requires: CMakeFiles/ft_ls.dir/main.c.o.requires
CMakeFiles/ft_ls.dir/requires: CMakeFiles/ft_ls.dir/mauxiliary.c.o.requires
CMakeFiles/ft_ls.dir/requires: CMakeFiles/ft_ls.dir/rightstypes.c.o.requires

.PHONY : CMakeFiles/ft_ls.dir/requires

CMakeFiles/ft_ls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ft_ls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ft_ls.dir/clean

CMakeFiles/ft_ls.dir/depend:
	cd /Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ariabyi/CLionProjects/ft_ls /Users/ariabyi/CLionProjects/ft_ls /Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug /Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug /Users/ariabyi/CLionProjects/ft_ls/cmake-build-debug/CMakeFiles/ft_ls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ft_ls.dir/depend

