# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ivons\CLionProjects\YgK-NN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ivons\CLionProjects\YgK-NN\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EXMM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EXMM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EXMM.dir/flags.make

CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.obj: CMakeFiles/EXMM.dir/flags.make
CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.obj: CMakeFiles/EXMM.dir/includes_C.rsp
CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.obj: ../ejecutarMinMonticulo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ivons\CLionProjects\YgK-NN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\EXMM.dir\ejecutarMinMonticulo.c.obj   -c C:\Users\ivons\CLionProjects\YgK-NN\ejecutarMinMonticulo.c

CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ivons\CLionProjects\YgK-NN\ejecutarMinMonticulo.c > CMakeFiles\EXMM.dir\ejecutarMinMonticulo.c.i

CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ivons\CLionProjects\YgK-NN\ejecutarMinMonticulo.c -o CMakeFiles\EXMM.dir\ejecutarMinMonticulo.c.s

CMakeFiles/EXMM.dir/maxMonticulo.c.obj: CMakeFiles/EXMM.dir/flags.make
CMakeFiles/EXMM.dir/maxMonticulo.c.obj: CMakeFiles/EXMM.dir/includes_C.rsp
CMakeFiles/EXMM.dir/maxMonticulo.c.obj: ../maxMonticulo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ivons\CLionProjects\YgK-NN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/EXMM.dir/maxMonticulo.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\EXMM.dir\maxMonticulo.c.obj   -c C:\Users\ivons\CLionProjects\YgK-NN\maxMonticulo.c

CMakeFiles/EXMM.dir/maxMonticulo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/EXMM.dir/maxMonticulo.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ivons\CLionProjects\YgK-NN\maxMonticulo.c > CMakeFiles\EXMM.dir\maxMonticulo.c.i

CMakeFiles/EXMM.dir/maxMonticulo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/EXMM.dir/maxMonticulo.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ivons\CLionProjects\YgK-NN\maxMonticulo.c -o CMakeFiles\EXMM.dir\maxMonticulo.c.s

# Object files for target EXMM
EXMM_OBJECTS = \
"CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.obj" \
"CMakeFiles/EXMM.dir/maxMonticulo.c.obj"

# External object files for target EXMM
EXMM_EXTERNAL_OBJECTS =

EXMM.exe: CMakeFiles/EXMM.dir/ejecutarMinMonticulo.c.obj
EXMM.exe: CMakeFiles/EXMM.dir/maxMonticulo.c.obj
EXMM.exe: CMakeFiles/EXMM.dir/build.make
EXMM.exe: CMakeFiles/EXMM.dir/linklibs.rsp
EXMM.exe: CMakeFiles/EXMM.dir/objects1.rsp
EXMM.exe: CMakeFiles/EXMM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ivons\CLionProjects\YgK-NN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable EXMM.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EXMM.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EXMM.dir/build: EXMM.exe

.PHONY : CMakeFiles/EXMM.dir/build

CMakeFiles/EXMM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EXMM.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EXMM.dir/clean

CMakeFiles/EXMM.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ivons\CLionProjects\YgK-NN C:\Users\ivons\CLionProjects\YgK-NN C:\Users\ivons\CLionProjects\YgK-NN\cmake-build-debug C:\Users\ivons\CLionProjects\YgK-NN\cmake-build-debug C:\Users\ivons\CLionProjects\YgK-NN\cmake-build-debug\CMakeFiles\EXMM.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EXMM.dir/depend
