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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build

# Include any dependencies generated for this target.
include CMakeFiles/SUNY_VM.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SUNY_VM.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SUNY_VM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SUNY_VM.dir/flags.make

CMakeFiles/SUNY_VM.dir/VM.c.o: CMakeFiles/SUNY_VM.dir/flags.make
CMakeFiles/SUNY_VM.dir/VM.c.o: ../VM.c
CMakeFiles/SUNY_VM.dir/VM.c.o: CMakeFiles/SUNY_VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SUNY_VM.dir/VM.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SUNY_VM.dir/VM.c.o -MF CMakeFiles/SUNY_VM.dir/VM.c.o.d -o CMakeFiles/SUNY_VM.dir/VM.c.o -c /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/VM.c

CMakeFiles/SUNY_VM.dir/VM.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SUNY_VM.dir/VM.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/VM.c > CMakeFiles/SUNY_VM.dir/VM.c.i

CMakeFiles/SUNY_VM.dir/VM.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SUNY_VM.dir/VM.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/VM.c -o CMakeFiles/SUNY_VM.dir/VM.c.s

CMakeFiles/SUNY_VM.dir/tape.c.o: CMakeFiles/SUNY_VM.dir/flags.make
CMakeFiles/SUNY_VM.dir/tape.c.o: ../tape.c
CMakeFiles/SUNY_VM.dir/tape.c.o: CMakeFiles/SUNY_VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SUNY_VM.dir/tape.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SUNY_VM.dir/tape.c.o -MF CMakeFiles/SUNY_VM.dir/tape.c.o.d -o CMakeFiles/SUNY_VM.dir/tape.c.o -c /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/tape.c

CMakeFiles/SUNY_VM.dir/tape.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SUNY_VM.dir/tape.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/tape.c > CMakeFiles/SUNY_VM.dir/tape.c.i

CMakeFiles/SUNY_VM.dir/tape.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SUNY_VM.dir/tape.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/tape.c -o CMakeFiles/SUNY_VM.dir/tape.c.s

# Object files for target SUNY_VM
SUNY_VM_OBJECTS = \
"CMakeFiles/SUNY_VM.dir/VM.c.o" \
"CMakeFiles/SUNY_VM.dir/tape.c.o"

# External object files for target SUNY_VM
SUNY_VM_EXTERNAL_OBJECTS =

SUNY_VM: CMakeFiles/SUNY_VM.dir/VM.c.o
SUNY_VM: CMakeFiles/SUNY_VM.dir/tape.c.o
SUNY_VM: CMakeFiles/SUNY_VM.dir/build.make
SUNY_VM: CMakeFiles/SUNY_VM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable SUNY_VM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SUNY_VM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SUNY_VM.dir/build: SUNY_VM
.PHONY : CMakeFiles/SUNY_VM.dir/build

CMakeFiles/SUNY_VM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SUNY_VM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SUNY_VM.dir/clean

CMakeFiles/SUNY_VM.dir/depend:
	cd /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build /home/rjmeeker3/SUNYPolySpring24/CS441_Comp_Sys_Arch/CS441TuringMachineProject/build/CMakeFiles/SUNY_VM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SUNY_VM.dir/depend

