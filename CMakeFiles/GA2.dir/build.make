# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/kushal/GA2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kushal/GA2

# Include any dependencies generated for this target.
include CMakeFiles/GA2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GA2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GA2.dir/flags.make

CMakeFiles/GA2.dir/src/input.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/input.cpp.o: src/input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GA2.dir/src/input.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/input.cpp.o -c /home/kushal/GA2/src/input.cpp

CMakeFiles/GA2.dir/src/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/input.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/input.cpp > CMakeFiles/GA2.dir/src/input.cpp.i

CMakeFiles/GA2.dir/src/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/input.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/input.cpp -o CMakeFiles/GA2.dir/src/input.cpp.s

CMakeFiles/GA2.dir/src/input.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/input.cpp.o.requires

CMakeFiles/GA2.dir/src/input.cpp.o.provides: CMakeFiles/GA2.dir/src/input.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/input.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/input.cpp.o.provides

CMakeFiles/GA2.dir/src/input.cpp.o.provides.build: CMakeFiles/GA2.dir/src/input.cpp.o


CMakeFiles/GA2.dir/src/boat.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/boat.cpp.o: src/boat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GA2.dir/src/boat.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/boat.cpp.o -c /home/kushal/GA2/src/boat.cpp

CMakeFiles/GA2.dir/src/boat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/boat.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/boat.cpp > CMakeFiles/GA2.dir/src/boat.cpp.i

CMakeFiles/GA2.dir/src/boat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/boat.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/boat.cpp -o CMakeFiles/GA2.dir/src/boat.cpp.s

CMakeFiles/GA2.dir/src/boat.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/boat.cpp.o.requires

CMakeFiles/GA2.dir/src/boat.cpp.o.provides: CMakeFiles/GA2.dir/src/boat.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/boat.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/boat.cpp.o.provides

CMakeFiles/GA2.dir/src/boat.cpp.o.provides.build: CMakeFiles/GA2.dir/src/boat.cpp.o


CMakeFiles/GA2.dir/src/nonedit.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/nonedit.cpp.o: src/nonedit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GA2.dir/src/nonedit.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/nonedit.cpp.o -c /home/kushal/GA2/src/nonedit.cpp

CMakeFiles/GA2.dir/src/nonedit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/nonedit.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/nonedit.cpp > CMakeFiles/GA2.dir/src/nonedit.cpp.i

CMakeFiles/GA2.dir/src/nonedit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/nonedit.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/nonedit.cpp -o CMakeFiles/GA2.dir/src/nonedit.cpp.s

CMakeFiles/GA2.dir/src/nonedit.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/nonedit.cpp.o.requires

CMakeFiles/GA2.dir/src/nonedit.cpp.o.provides: CMakeFiles/GA2.dir/src/nonedit.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/nonedit.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/nonedit.cpp.o.provides

CMakeFiles/GA2.dir/src/nonedit.cpp.o.provides.build: CMakeFiles/GA2.dir/src/nonedit.cpp.o


CMakeFiles/GA2.dir/src/main.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GA2.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/main.cpp.o -c /home/kushal/GA2/src/main.cpp

CMakeFiles/GA2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/main.cpp > CMakeFiles/GA2.dir/src/main.cpp.i

CMakeFiles/GA2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/main.cpp -o CMakeFiles/GA2.dir/src/main.cpp.s

CMakeFiles/GA2.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/main.cpp.o.requires

CMakeFiles/GA2.dir/src/main.cpp.o.provides: CMakeFiles/GA2.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/main.cpp.o.provides

CMakeFiles/GA2.dir/src/main.cpp.o.provides.build: CMakeFiles/GA2.dir/src/main.cpp.o


CMakeFiles/GA2.dir/src/other_handlers.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/other_handlers.cpp.o: src/other_handlers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GA2.dir/src/other_handlers.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/other_handlers.cpp.o -c /home/kushal/GA2/src/other_handlers.cpp

CMakeFiles/GA2.dir/src/other_handlers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/other_handlers.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/other_handlers.cpp > CMakeFiles/GA2.dir/src/other_handlers.cpp.i

CMakeFiles/GA2.dir/src/other_handlers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/other_handlers.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/other_handlers.cpp -o CMakeFiles/GA2.dir/src/other_handlers.cpp.s

CMakeFiles/GA2.dir/src/other_handlers.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/other_handlers.cpp.o.requires

CMakeFiles/GA2.dir/src/other_handlers.cpp.o.provides: CMakeFiles/GA2.dir/src/other_handlers.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/other_handlers.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/other_handlers.cpp.o.provides

CMakeFiles/GA2.dir/src/other_handlers.cpp.o.provides.build: CMakeFiles/GA2.dir/src/other_handlers.cpp.o


CMakeFiles/GA2.dir/src/ball.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/ball.cpp.o: src/ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/GA2.dir/src/ball.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/ball.cpp.o -c /home/kushal/GA2/src/ball.cpp

CMakeFiles/GA2.dir/src/ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/ball.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/ball.cpp > CMakeFiles/GA2.dir/src/ball.cpp.i

CMakeFiles/GA2.dir/src/ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/ball.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/ball.cpp -o CMakeFiles/GA2.dir/src/ball.cpp.s

CMakeFiles/GA2.dir/src/ball.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/ball.cpp.o.requires

CMakeFiles/GA2.dir/src/ball.cpp.o.provides: CMakeFiles/GA2.dir/src/ball.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/ball.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/ball.cpp.o.provides

CMakeFiles/GA2.dir/src/ball.cpp.o.provides.build: CMakeFiles/GA2.dir/src/ball.cpp.o


CMakeFiles/GA2.dir/src/timer.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/timer.cpp.o: src/timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/GA2.dir/src/timer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/timer.cpp.o -c /home/kushal/GA2/src/timer.cpp

CMakeFiles/GA2.dir/src/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/timer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/timer.cpp > CMakeFiles/GA2.dir/src/timer.cpp.i

CMakeFiles/GA2.dir/src/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/timer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/timer.cpp -o CMakeFiles/GA2.dir/src/timer.cpp.s

CMakeFiles/GA2.dir/src/timer.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/timer.cpp.o.requires

CMakeFiles/GA2.dir/src/timer.cpp.o.provides: CMakeFiles/GA2.dir/src/timer.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/timer.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/timer.cpp.o.provides

CMakeFiles/GA2.dir/src/timer.cpp.o.provides.build: CMakeFiles/GA2.dir/src/timer.cpp.o


CMakeFiles/GA2.dir/src/color.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/color.cpp.o: src/color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/GA2.dir/src/color.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/color.cpp.o -c /home/kushal/GA2/src/color.cpp

CMakeFiles/GA2.dir/src/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/color.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/color.cpp > CMakeFiles/GA2.dir/src/color.cpp.i

CMakeFiles/GA2.dir/src/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/color.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/color.cpp -o CMakeFiles/GA2.dir/src/color.cpp.s

CMakeFiles/GA2.dir/src/color.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/color.cpp.o.requires

CMakeFiles/GA2.dir/src/color.cpp.o.provides: CMakeFiles/GA2.dir/src/color.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/color.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/color.cpp.o.provides

CMakeFiles/GA2.dir/src/color.cpp.o.provides.build: CMakeFiles/GA2.dir/src/color.cpp.o


CMakeFiles/GA2.dir/src/water.cpp.o: CMakeFiles/GA2.dir/flags.make
CMakeFiles/GA2.dir/src/water.cpp.o: src/water.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/GA2.dir/src/water.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GA2.dir/src/water.cpp.o -c /home/kushal/GA2/src/water.cpp

CMakeFiles/GA2.dir/src/water.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GA2.dir/src/water.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kushal/GA2/src/water.cpp > CMakeFiles/GA2.dir/src/water.cpp.i

CMakeFiles/GA2.dir/src/water.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GA2.dir/src/water.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kushal/GA2/src/water.cpp -o CMakeFiles/GA2.dir/src/water.cpp.s

CMakeFiles/GA2.dir/src/water.cpp.o.requires:

.PHONY : CMakeFiles/GA2.dir/src/water.cpp.o.requires

CMakeFiles/GA2.dir/src/water.cpp.o.provides: CMakeFiles/GA2.dir/src/water.cpp.o.requires
	$(MAKE) -f CMakeFiles/GA2.dir/build.make CMakeFiles/GA2.dir/src/water.cpp.o.provides.build
.PHONY : CMakeFiles/GA2.dir/src/water.cpp.o.provides

CMakeFiles/GA2.dir/src/water.cpp.o.provides.build: CMakeFiles/GA2.dir/src/water.cpp.o


# Object files for target GA2
GA2_OBJECTS = \
"CMakeFiles/GA2.dir/src/input.cpp.o" \
"CMakeFiles/GA2.dir/src/boat.cpp.o" \
"CMakeFiles/GA2.dir/src/nonedit.cpp.o" \
"CMakeFiles/GA2.dir/src/main.cpp.o" \
"CMakeFiles/GA2.dir/src/other_handlers.cpp.o" \
"CMakeFiles/GA2.dir/src/ball.cpp.o" \
"CMakeFiles/GA2.dir/src/timer.cpp.o" \
"CMakeFiles/GA2.dir/src/color.cpp.o" \
"CMakeFiles/GA2.dir/src/water.cpp.o"

# External object files for target GA2
GA2_EXTERNAL_OBJECTS =

GA2: CMakeFiles/GA2.dir/src/input.cpp.o
GA2: CMakeFiles/GA2.dir/src/boat.cpp.o
GA2: CMakeFiles/GA2.dir/src/nonedit.cpp.o
GA2: CMakeFiles/GA2.dir/src/main.cpp.o
GA2: CMakeFiles/GA2.dir/src/other_handlers.cpp.o
GA2: CMakeFiles/GA2.dir/src/ball.cpp.o
GA2: CMakeFiles/GA2.dir/src/timer.cpp.o
GA2: CMakeFiles/GA2.dir/src/color.cpp.o
GA2: CMakeFiles/GA2.dir/src/water.cpp.o
GA2: CMakeFiles/GA2.dir/build.make
GA2: CMakeFiles/GA2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kushal/GA2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable GA2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GA2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GA2.dir/build: GA2

.PHONY : CMakeFiles/GA2.dir/build

CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/input.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/boat.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/nonedit.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/main.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/other_handlers.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/ball.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/timer.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/color.cpp.o.requires
CMakeFiles/GA2.dir/requires: CMakeFiles/GA2.dir/src/water.cpp.o.requires

.PHONY : CMakeFiles/GA2.dir/requires

CMakeFiles/GA2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GA2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GA2.dir/clean

CMakeFiles/GA2.dir/depend:
	cd /home/kushal/GA2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kushal/GA2 /home/kushal/GA2 /home/kushal/GA2 /home/kushal/GA2 /home/kushal/GA2/CMakeFiles/GA2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GA2.dir/depend
