# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/vito/workspace1/HW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vito/workspace1/HW2/build

# Include any dependencies generated for this target.
include CMakeFiles/hw2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw2.dir/flags.make

CMakeFiles/hw2.dir/output.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/output.o: ../output.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vito/workspace1/HW2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/hw2.dir/output.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hw2.dir/output.o   -c /home/vito/workspace1/HW2/output.c

CMakeFiles/hw2.dir/output.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw2.dir/output.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/vito/workspace1/HW2/output.c > CMakeFiles/hw2.dir/output.i

CMakeFiles/hw2.dir/output.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw2.dir/output.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/vito/workspace1/HW2/output.c -o CMakeFiles/hw2.dir/output.s

CMakeFiles/hw2.dir/output.o.requires:
.PHONY : CMakeFiles/hw2.dir/output.o.requires

CMakeFiles/hw2.dir/output.o.provides: CMakeFiles/hw2.dir/output.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/output.o.provides.build
.PHONY : CMakeFiles/hw2.dir/output.o.provides

CMakeFiles/hw2.dir/output.o.provides.build: CMakeFiles/hw2.dir/output.o

CMakeFiles/hw2.dir/str.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/str.o: ../str.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vito/workspace1/HW2/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/hw2.dir/str.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hw2.dir/str.o   -c /home/vito/workspace1/HW2/str.c

CMakeFiles/hw2.dir/str.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw2.dir/str.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/vito/workspace1/HW2/str.c > CMakeFiles/hw2.dir/str.i

CMakeFiles/hw2.dir/str.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw2.dir/str.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/vito/workspace1/HW2/str.c -o CMakeFiles/hw2.dir/str.s

CMakeFiles/hw2.dir/str.o.requires:
.PHONY : CMakeFiles/hw2.dir/str.o.requires

CMakeFiles/hw2.dir/str.o.provides: CMakeFiles/hw2.dir/str.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/str.o.provides.build
.PHONY : CMakeFiles/hw2.dir/str.o.provides

CMakeFiles/hw2.dir/str.o.provides.build: CMakeFiles/hw2.dir/str.o

CMakeFiles/hw2.dir/main.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/main.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vito/workspace1/HW2/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/hw2.dir/main.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hw2.dir/main.o   -c /home/vito/workspace1/HW2/main.c

CMakeFiles/hw2.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw2.dir/main.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/vito/workspace1/HW2/main.c > CMakeFiles/hw2.dir/main.i

CMakeFiles/hw2.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw2.dir/main.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/vito/workspace1/HW2/main.c -o CMakeFiles/hw2.dir/main.s

CMakeFiles/hw2.dir/main.o.requires:
.PHONY : CMakeFiles/hw2.dir/main.o.requires

CMakeFiles/hw2.dir/main.o.provides: CMakeFiles/hw2.dir/main.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/main.o.provides.build
.PHONY : CMakeFiles/hw2.dir/main.o.provides

CMakeFiles/hw2.dir/main.o.provides.build: CMakeFiles/hw2.dir/main.o

CMakeFiles/hw2.dir/replace.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/replace.o: ../replace.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vito/workspace1/HW2/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/hw2.dir/replace.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hw2.dir/replace.o   -c /home/vito/workspace1/HW2/replace.c

CMakeFiles/hw2.dir/replace.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw2.dir/replace.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/vito/workspace1/HW2/replace.c > CMakeFiles/hw2.dir/replace.i

CMakeFiles/hw2.dir/replace.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw2.dir/replace.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/vito/workspace1/HW2/replace.c -o CMakeFiles/hw2.dir/replace.s

CMakeFiles/hw2.dir/replace.o.requires:
.PHONY : CMakeFiles/hw2.dir/replace.o.requires

CMakeFiles/hw2.dir/replace.o.provides: CMakeFiles/hw2.dir/replace.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/replace.o.provides.build
.PHONY : CMakeFiles/hw2.dir/replace.o.provides

CMakeFiles/hw2.dir/replace.o.provides.build: CMakeFiles/hw2.dir/replace.o

CMakeFiles/hw2.dir/card.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/card.o: ../card.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vito/workspace1/HW2/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/hw2.dir/card.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hw2.dir/card.o   -c /home/vito/workspace1/HW2/card.c

CMakeFiles/hw2.dir/card.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw2.dir/card.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/vito/workspace1/HW2/card.c > CMakeFiles/hw2.dir/card.i

CMakeFiles/hw2.dir/card.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw2.dir/card.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/vito/workspace1/HW2/card.c -o CMakeFiles/hw2.dir/card.s

CMakeFiles/hw2.dir/card.o.requires:
.PHONY : CMakeFiles/hw2.dir/card.o.requires

CMakeFiles/hw2.dir/card.o.provides: CMakeFiles/hw2.dir/card.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/card.o.provides.build
.PHONY : CMakeFiles/hw2.dir/card.o.provides

CMakeFiles/hw2.dir/card.o.provides.build: CMakeFiles/hw2.dir/card.o

CMakeFiles/hw2.dir/dlist.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/dlist.o: ../dlist.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/vito/workspace1/HW2/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/hw2.dir/dlist.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hw2.dir/dlist.o   -c /home/vito/workspace1/HW2/dlist.c

CMakeFiles/hw2.dir/dlist.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw2.dir/dlist.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/vito/workspace1/HW2/dlist.c > CMakeFiles/hw2.dir/dlist.i

CMakeFiles/hw2.dir/dlist.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw2.dir/dlist.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/vito/workspace1/HW2/dlist.c -o CMakeFiles/hw2.dir/dlist.s

CMakeFiles/hw2.dir/dlist.o.requires:
.PHONY : CMakeFiles/hw2.dir/dlist.o.requires

CMakeFiles/hw2.dir/dlist.o.provides: CMakeFiles/hw2.dir/dlist.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/dlist.o.provides.build
.PHONY : CMakeFiles/hw2.dir/dlist.o.provides

CMakeFiles/hw2.dir/dlist.o.provides.build: CMakeFiles/hw2.dir/dlist.o

# Object files for target hw2
hw2_OBJECTS = \
"CMakeFiles/hw2.dir/output.o" \
"CMakeFiles/hw2.dir/str.o" \
"CMakeFiles/hw2.dir/main.o" \
"CMakeFiles/hw2.dir/replace.o" \
"CMakeFiles/hw2.dir/card.o" \
"CMakeFiles/hw2.dir/dlist.o"

# External object files for target hw2
hw2_EXTERNAL_OBJECTS =

hw2: CMakeFiles/hw2.dir/output.o
hw2: CMakeFiles/hw2.dir/str.o
hw2: CMakeFiles/hw2.dir/main.o
hw2: CMakeFiles/hw2.dir/replace.o
hw2: CMakeFiles/hw2.dir/card.o
hw2: CMakeFiles/hw2.dir/dlist.o
hw2: CMakeFiles/hw2.dir/build.make
hw2: CMakeFiles/hw2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable hw2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw2.dir/build: hw2
.PHONY : CMakeFiles/hw2.dir/build

CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/output.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/str.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/main.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/replace.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/card.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/dlist.o.requires
.PHONY : CMakeFiles/hw2.dir/requires

CMakeFiles/hw2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw2.dir/clean

CMakeFiles/hw2.dir/depend:
	cd /home/vito/workspace1/HW2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vito/workspace1/HW2 /home/vito/workspace1/HW2 /home/vito/workspace1/HW2/build /home/vito/workspace1/HW2/build /home/vito/workspace1/HW2/build/CMakeFiles/hw2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw2.dir/depend
