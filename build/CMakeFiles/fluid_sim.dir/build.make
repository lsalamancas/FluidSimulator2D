# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = /usr/sbin/cmake

# The command to remove a file.
RM = /usr/sbin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fer/projects/FluidSimulator2D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fer/projects/FluidSimulator2D/build

# Include any dependencies generated for this target.
include CMakeFiles/fluid_sim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fluid_sim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fluid_sim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fluid_sim.dir/flags.make

CMakeFiles/fluid_sim.dir/codegen:
.PHONY : CMakeFiles/fluid_sim.dir/codegen

CMakeFiles/fluid_sim.dir/src/main.cpp.o: CMakeFiles/fluid_sim.dir/flags.make
CMakeFiles/fluid_sim.dir/src/main.cpp.o: /home/fer/projects/FluidSimulator2D/src/main.cpp
CMakeFiles/fluid_sim.dir/src/main.cpp.o: CMakeFiles/fluid_sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fer/projects/FluidSimulator2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fluid_sim.dir/src/main.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fluid_sim.dir/src/main.cpp.o -MF CMakeFiles/fluid_sim.dir/src/main.cpp.o.d -o CMakeFiles/fluid_sim.dir/src/main.cpp.o -c /home/fer/projects/FluidSimulator2D/src/main.cpp

CMakeFiles/fluid_sim.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fluid_sim.dir/src/main.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fer/projects/FluidSimulator2D/src/main.cpp > CMakeFiles/fluid_sim.dir/src/main.cpp.i

CMakeFiles/fluid_sim.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fluid_sim.dir/src/main.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fer/projects/FluidSimulator2D/src/main.cpp -o CMakeFiles/fluid_sim.dir/src/main.cpp.s

CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o: CMakeFiles/fluid_sim.dir/flags.make
CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o: /home/fer/projects/FluidSimulator2D/src/Renderer.cpp
CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o: CMakeFiles/fluid_sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fer/projects/FluidSimulator2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o -MF CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o.d -o CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o -c /home/fer/projects/FluidSimulator2D/src/Renderer.cpp

CMakeFiles/fluid_sim.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fluid_sim.dir/src/Renderer.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fer/projects/FluidSimulator2D/src/Renderer.cpp > CMakeFiles/fluid_sim.dir/src/Renderer.cpp.i

CMakeFiles/fluid_sim.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fluid_sim.dir/src/Renderer.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fer/projects/FluidSimulator2D/src/Renderer.cpp -o CMakeFiles/fluid_sim.dir/src/Renderer.cpp.s

CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o: CMakeFiles/fluid_sim.dir/flags.make
CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o: /home/fer/projects/FluidSimulator2D/src/ParticleSystem.cpp
CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o: CMakeFiles/fluid_sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fer/projects/FluidSimulator2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o -MF CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o.d -o CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o -c /home/fer/projects/FluidSimulator2D/src/ParticleSystem.cpp

CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fer/projects/FluidSimulator2D/src/ParticleSystem.cpp > CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.i

CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fer/projects/FluidSimulator2D/src/ParticleSystem.cpp -o CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.s

CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o: CMakeFiles/fluid_sim.dir/flags.make
CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o: /home/fer/projects/FluidSimulator2D/src/FluidSolver.cpp
CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o: CMakeFiles/fluid_sim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/fer/projects/FluidSimulator2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o -MF CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o.d -o CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o -c /home/fer/projects/FluidSimulator2D/src/FluidSolver.cpp

CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fer/projects/FluidSimulator2D/src/FluidSolver.cpp > CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.i

CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fer/projects/FluidSimulator2D/src/FluidSolver.cpp -o CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.s

# Object files for target fluid_sim
fluid_sim_OBJECTS = \
"CMakeFiles/fluid_sim.dir/src/main.cpp.o" \
"CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o" \
"CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o" \
"CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o"

# External object files for target fluid_sim
fluid_sim_EXTERNAL_OBJECTS =

fluid_sim: CMakeFiles/fluid_sim.dir/src/main.cpp.o
fluid_sim: CMakeFiles/fluid_sim.dir/src/Renderer.cpp.o
fluid_sim: CMakeFiles/fluid_sim.dir/src/ParticleSystem.cpp.o
fluid_sim: CMakeFiles/fluid_sim.dir/src/FluidSolver.cpp.o
fluid_sim: CMakeFiles/fluid_sim.dir/build.make
fluid_sim: CMakeFiles/fluid_sim.dir/compiler_depend.ts
fluid_sim: /usr/lib/libglfw.so.3.4
fluid_sim: /usr/lib/libGLX.so
fluid_sim: /usr/lib/libOpenGL.so
fluid_sim: CMakeFiles/fluid_sim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/fer/projects/FluidSimulator2D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable fluid_sim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fluid_sim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fluid_sim.dir/build: fluid_sim
.PHONY : CMakeFiles/fluid_sim.dir/build

CMakeFiles/fluid_sim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fluid_sim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fluid_sim.dir/clean

CMakeFiles/fluid_sim.dir/depend:
	cd /home/fer/projects/FluidSimulator2D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fer/projects/FluidSimulator2D /home/fer/projects/FluidSimulator2D /home/fer/projects/FluidSimulator2D/build /home/fer/projects/FluidSimulator2D/build /home/fer/projects/FluidSimulator2D/build/CMakeFiles/fluid_sim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/fluid_sim.dir/depend

