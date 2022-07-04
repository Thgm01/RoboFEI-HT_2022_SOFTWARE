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
CMAKE_SOURCE_DIR = /home/robofei/ROS2/src/walk_test/src/control

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robofei/ROS2/build/control

# Include any dependencies generated for this target.
include CMakeFiles/motion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motion.dir/flags.make

CMakeFiles/motion.dir/src/motion/MotionManager.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/motion/MotionManager.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/motion.dir/src/motion/MotionManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/motion/MotionManager.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionManager.cpp

CMakeFiles/motion.dir/src/motion/MotionManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/motion/MotionManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionManager.cpp > CMakeFiles/motion.dir/src/motion/MotionManager.cpp.i

CMakeFiles/motion.dir/src/motion/MotionManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/motion/MotionManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionManager.cpp -o CMakeFiles/motion.dir/src/motion/MotionManager.cpp.s

CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Walking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Walking.cpp

CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Walking.cpp > CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.i

CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Walking.cpp -o CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.s

CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/motion/AngleEstimator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/motion/AngleEstimator.cpp

CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/motion/AngleEstimator.cpp > CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.i

CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/motion/AngleEstimator.cpp -o CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.s

CMakeFiles/motion.dir/src/math/Matrix.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/math/Matrix.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/math/Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/motion.dir/src/math/Matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/math/Matrix.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/math/Matrix.cpp

CMakeFiles/motion.dir/src/math/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/math/Matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/math/Matrix.cpp > CMakeFiles/motion.dir/src/math/Matrix.cpp.i

CMakeFiles/motion.dir/src/math/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/math/Matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/math/Matrix.cpp -o CMakeFiles/motion.dir/src/math/Matrix.cpp.s

CMakeFiles/motion.dir/src/math/Plane.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/math/Plane.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/math/Plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/motion.dir/src/math/Plane.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/math/Plane.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/math/Plane.cpp

CMakeFiles/motion.dir/src/math/Plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/math/Plane.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/math/Plane.cpp > CMakeFiles/motion.dir/src/math/Plane.cpp.i

CMakeFiles/motion.dir/src/math/Plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/math/Plane.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/math/Plane.cpp -o CMakeFiles/motion.dir/src/math/Plane.cpp.s

CMakeFiles/motion.dir/src/math/Point.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/math/Point.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/math/Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/motion.dir/src/math/Point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/math/Point.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/math/Point.cpp

CMakeFiles/motion.dir/src/math/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/math/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/math/Point.cpp > CMakeFiles/motion.dir/src/math/Point.cpp.i

CMakeFiles/motion.dir/src/math/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/math/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/math/Point.cpp -o CMakeFiles/motion.dir/src/math/Point.cpp.s

CMakeFiles/motion.dir/src/math/Vector.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/math/Vector.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/math/Vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/motion.dir/src/math/Vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/math/Vector.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/math/Vector.cpp

CMakeFiles/motion.dir/src/math/Vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/math/Vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/math/Vector.cpp > CMakeFiles/motion.dir/src/math/Vector.cpp.i

CMakeFiles/motion.dir/src/math/Vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/math/Vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/math/Vector.cpp -o CMakeFiles/motion.dir/src/math/Vector.cpp.s

CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/math/QuadraticStateTransform.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/math/QuadraticStateTransform.cpp

CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/math/QuadraticStateTransform.cpp > CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.i

CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/math/QuadraticStateTransform.cpp -o CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.s

CMakeFiles/motion.dir/src/math/MotionState.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/math/MotionState.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/math/MotionState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/motion.dir/src/math/MotionState.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/math/MotionState.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/math/MotionState.cpp

CMakeFiles/motion.dir/src/math/MotionState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/math/MotionState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/math/MotionState.cpp > CMakeFiles/motion.dir/src/math/MotionState.cpp.i

CMakeFiles/motion.dir/src/math/MotionState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/math/MotionState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/math/MotionState.cpp -o CMakeFiles/motion.dir/src/math/MotionState.cpp.s

CMakeFiles/motion.dir/src/motion/JointData.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/motion/JointData.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/motion/JointData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/motion.dir/src/motion/JointData.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/motion/JointData.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/motion/JointData.cpp

CMakeFiles/motion.dir/src/motion/JointData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/motion/JointData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/motion/JointData.cpp > CMakeFiles/motion.dir/src/motion/JointData.cpp.i

CMakeFiles/motion.dir/src/motion/JointData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/motion/JointData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/motion/JointData.cpp -o CMakeFiles/motion.dir/src/motion/JointData.cpp.s

CMakeFiles/motion.dir/src/motion/Kinematics.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/motion/Kinematics.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/motion/Kinematics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/motion.dir/src/motion/Kinematics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/motion/Kinematics.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/motion/Kinematics.cpp

CMakeFiles/motion.dir/src/motion/Kinematics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/motion/Kinematics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/motion/Kinematics.cpp > CMakeFiles/motion.dir/src/motion/Kinematics.cpp.i

CMakeFiles/motion.dir/src/motion/Kinematics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/motion/Kinematics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/motion/Kinematics.cpp -o CMakeFiles/motion.dir/src/motion/Kinematics.cpp.s

CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionStatus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionStatus.cpp

CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionStatus.cpp > CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.i

CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/motion/MotionStatus.cpp -o CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.s

CMakeFiles/motion.dir/src/motion/modules/Action.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/motion/modules/Action.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/motion.dir/src/motion/modules/Action.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/motion/modules/Action.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Action.cpp

CMakeFiles/motion.dir/src/motion/modules/Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/motion/modules/Action.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Action.cpp > CMakeFiles/motion.dir/src/motion/modules/Action.cpp.i

CMakeFiles/motion.dir/src/motion/modules/Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/motion/modules/Action.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/motion/modules/Action.cpp -o CMakeFiles/motion.dir/src/motion/modules/Action.cpp.s

CMakeFiles/motion.dir/src/minIni/minIni.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/minIni/minIni.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/minIni/minIni.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/motion.dir/src/minIni/minIni.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/minIni/minIni.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/minIni/minIni.cpp

CMakeFiles/motion.dir/src/minIni/minIni.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/minIni/minIni.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/minIni/minIni.cpp > CMakeFiles/motion.dir/src/minIni/minIni.cpp.i

CMakeFiles/motion.dir/src/minIni/minIni.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/minIni/minIni.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/minIni/minIni.cpp -o CMakeFiles/motion.dir/src/minIni/minIni.cpp.s

CMakeFiles/motion.dir/src/GaitMove.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/GaitMove.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/GaitMove.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/motion.dir/src/GaitMove.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/GaitMove.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/GaitMove.cpp

CMakeFiles/motion.dir/src/GaitMove.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/GaitMove.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/GaitMove.cpp > CMakeFiles/motion.dir/src/GaitMove.cpp.i

CMakeFiles/motion.dir/src/GaitMove.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/GaitMove.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/GaitMove.cpp -o CMakeFiles/motion.dir/src/GaitMove.cpp.s

CMakeFiles/motion.dir/src/ReadConfig.cpp.o: CMakeFiles/motion.dir/flags.make
CMakeFiles/motion.dir/src/ReadConfig.cpp.o: /home/robofei/ROS2/src/walk_test/src/control/src/ReadConfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/motion.dir/src/ReadConfig.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motion.dir/src/ReadConfig.cpp.o -c /home/robofei/ROS2/src/walk_test/src/control/src/ReadConfig.cpp

CMakeFiles/motion.dir/src/ReadConfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motion.dir/src/ReadConfig.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robofei/ROS2/src/walk_test/src/control/src/ReadConfig.cpp > CMakeFiles/motion.dir/src/ReadConfig.cpp.i

CMakeFiles/motion.dir/src/ReadConfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motion.dir/src/ReadConfig.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robofei/ROS2/src/walk_test/src/control/src/ReadConfig.cpp -o CMakeFiles/motion.dir/src/ReadConfig.cpp.s

# Object files for target motion
motion_OBJECTS = \
"CMakeFiles/motion.dir/src/motion/MotionManager.cpp.o" \
"CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.o" \
"CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.o" \
"CMakeFiles/motion.dir/src/math/Matrix.cpp.o" \
"CMakeFiles/motion.dir/src/math/Plane.cpp.o" \
"CMakeFiles/motion.dir/src/math/Point.cpp.o" \
"CMakeFiles/motion.dir/src/math/Vector.cpp.o" \
"CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.o" \
"CMakeFiles/motion.dir/src/math/MotionState.cpp.o" \
"CMakeFiles/motion.dir/src/motion/JointData.cpp.o" \
"CMakeFiles/motion.dir/src/motion/Kinematics.cpp.o" \
"CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.o" \
"CMakeFiles/motion.dir/src/motion/modules/Action.cpp.o" \
"CMakeFiles/motion.dir/src/minIni/minIni.cpp.o" \
"CMakeFiles/motion.dir/src/GaitMove.cpp.o" \
"CMakeFiles/motion.dir/src/ReadConfig.cpp.o"

# External object files for target motion
motion_EXTERNAL_OBJECTS =

libmotion.so: CMakeFiles/motion.dir/src/motion/MotionManager.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/motion/modules/Walking.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/motion/AngleEstimator.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/math/Matrix.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/math/Plane.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/math/Point.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/math/Vector.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/math/QuadraticStateTransform.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/math/MotionState.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/motion/JointData.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/motion/Kinematics.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/motion/MotionStatus.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/motion/modules/Action.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/minIni/minIni.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/GaitMove.cpp.o
libmotion.so: CMakeFiles/motion.dir/src/ReadConfig.cpp.o
libmotion.so: CMakeFiles/motion.dir/build.make
libmotion.so: /opt/ros/foxy/lib/libcomponent_manager.so
libmotion.so: /home/robofei/ROS2/install/dynamixel_sdk_custom_interfaces/lib/libdynamixel_sdk_custom_interfaces__rosidl_typesupport_introspection_c.so
libmotion.so: /home/robofei/ROS2/install/dynamixel_sdk_custom_interfaces/lib/libdynamixel_sdk_custom_interfaces__rosidl_typesupport_c.so
libmotion.so: /home/robofei/ROS2/install/dynamixel_sdk_custom_interfaces/lib/libdynamixel_sdk_custom_interfaces__rosidl_typesupport_introspection_cpp.so
libmotion.so: /home/robofei/ROS2/install/dynamixel_sdk_custom_interfaces/lib/libdynamixel_sdk_custom_interfaces__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/libsensor_msgs__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/librclcpp.so
libmotion.so: /opt/ros/foxy/lib/liblibstatistics_collector.so
libmotion.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/librcl.so
libmotion.so: /opt/ros/foxy/lib/librmw_implementation.so
libmotion.so: /opt/ros/foxy/lib/librmw.so
libmotion.so: /opt/ros/foxy/lib/librcl_logging_spdlog.so
libmotion.so: /usr/lib/x86_64-linux-gnu/libspdlog.so.1.5.0
libmotion.so: /opt/ros/foxy/lib/librcl_yaml_param_parser.so
libmotion.so: /opt/ros/foxy/lib/libyaml.so
libmotion.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/libtracetools.so
libmotion.so: /opt/ros/foxy/lib/libament_index_cpp.so
libmotion.so: /opt/ros/foxy/lib/libclass_loader.so
libmotion.so: /opt/ros/foxy/lib/x86_64-linux-gnu/libconsole_bridge.so.1.0
libmotion.so: /opt/ros/foxy/lib/libcomposition_interfaces__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/libcomposition_interfaces__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/libcomposition_interfaces__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/libcomposition_interfaces__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/libcomposition_interfaces__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/librcl_interfaces__rosidl_typesupport_cpp.so
libmotion.so: /home/robofei/ROS2/install/dynamixel_sdk_custom_interfaces/lib/libdynamixel_sdk_custom_interfaces__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/libsensor_msgs__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/libgeometry_msgs__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/libstd_msgs__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_generator_c.so
libmotion.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/librosidl_typesupport_introspection_cpp.so
libmotion.so: /opt/ros/foxy/lib/librosidl_typesupport_introspection_c.so
libmotion.so: /opt/ros/foxy/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/librosidl_typesupport_cpp.so
libmotion.so: /opt/ros/foxy/lib/librosidl_typesupport_c.so
libmotion.so: /opt/ros/foxy/lib/librcpputils.so
libmotion.so: /opt/ros/foxy/lib/librosidl_runtime_c.so
libmotion.so: /opt/ros/foxy/lib/librcutils.so
libmotion.so: CMakeFiles/motion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robofei/ROS2/build/control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX shared library libmotion.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motion.dir/build: libmotion.so

.PHONY : CMakeFiles/motion.dir/build

CMakeFiles/motion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motion.dir/clean

CMakeFiles/motion.dir/depend:
	cd /home/robofei/ROS2/build/control && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robofei/ROS2/src/walk_test/src/control /home/robofei/ROS2/src/walk_test/src/control /home/robofei/ROS2/build/control /home/robofei/ROS2/build/control /home/robofei/ROS2/build/control/CMakeFiles/motion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/motion.dir/depend
