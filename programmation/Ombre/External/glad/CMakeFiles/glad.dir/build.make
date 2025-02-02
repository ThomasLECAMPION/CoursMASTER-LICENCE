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
CMAKE_SOURCE_DIR = /home/ectomic/Bureau/programmation/Ombre

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ectomic/Bureau/programmation/Ombre

# Include any dependencies generated for this target.
include External/glad/CMakeFiles/glad.dir/depend.make

# Include the progress variables for this target.
include External/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include External/glad/CMakeFiles/glad.dir/flags.make

External/glad/src/glad.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ectomic/Bureau/programmation/Ombre/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating GLAD"
	cd /home/ectomic/Bureau/programmation/Ombre/External/glad && /usr/bin/python -m glad --profile=core --out-path=/home/ectomic/Bureau/programmation/Ombre/External/glad --api=gl=4.5,gles2= --generator=c --extensions= --spec=gl

External/glad/include/glad/glad.h: External/glad/src/glad.c
	@$(CMAKE_COMMAND) -E touch_nocreate External/glad/include/glad/glad.h

External/glad/CMakeFiles/glad.dir/src/glad.c.o: External/glad/CMakeFiles/glad.dir/flags.make
External/glad/CMakeFiles/glad.dir/src/glad.c.o: External/glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ectomic/Bureau/programmation/Ombre/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object External/glad/CMakeFiles/glad.dir/src/glad.c.o"
	cd /home/ectomic/Bureau/programmation/Ombre/External/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glad.dir/src/glad.c.o   -c /home/ectomic/Bureau/programmation/Ombre/External/glad/src/glad.c

External/glad/CMakeFiles/glad.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/glad.c.i"
	cd /home/ectomic/Bureau/programmation/Ombre/External/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ectomic/Bureau/programmation/Ombre/External/glad/src/glad.c > CMakeFiles/glad.dir/src/glad.c.i

External/glad/CMakeFiles/glad.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/glad.c.s"
	cd /home/ectomic/Bureau/programmation/Ombre/External/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ectomic/Bureau/programmation/Ombre/External/glad/src/glad.c -o CMakeFiles/glad.dir/src/glad.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/glad.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

External/glad/libglad.a: External/glad/CMakeFiles/glad.dir/src/glad.c.o
External/glad/libglad.a: External/glad/CMakeFiles/glad.dir/build.make
External/glad/libglad.a: External/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ectomic/Bureau/programmation/Ombre/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libglad.a"
	cd /home/ectomic/Bureau/programmation/Ombre/External/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/ectomic/Bureau/programmation/Ombre/External/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
External/glad/CMakeFiles/glad.dir/build: External/glad/libglad.a

.PHONY : External/glad/CMakeFiles/glad.dir/build

External/glad/CMakeFiles/glad.dir/clean:
	cd /home/ectomic/Bureau/programmation/Ombre/External/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : External/glad/CMakeFiles/glad.dir/clean

External/glad/CMakeFiles/glad.dir/depend: External/glad/src/glad.c
External/glad/CMakeFiles/glad.dir/depend: External/glad/include/glad/glad.h
	cd /home/ectomic/Bureau/programmation/Ombre && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ectomic/Bureau/programmation/Ombre /home/ectomic/Bureau/programmation/Ombre/External/glad /home/ectomic/Bureau/programmation/Ombre /home/ectomic/Bureau/programmation/Ombre/External/glad /home/ectomic/Bureau/programmation/Ombre/External/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : External/glad/CMakeFiles/glad.dir/depend

