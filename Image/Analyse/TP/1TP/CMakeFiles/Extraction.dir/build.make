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
CMAKE_SOURCE_DIR = /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP

# Include any dependencies generated for this target.
include CMakeFiles/Extraction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Extraction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Extraction.dir/flags.make

CMakeFiles/Extraction.dir/extraction.cpp.o: CMakeFiles/Extraction.dir/flags.make
CMakeFiles/Extraction.dir/extraction.cpp.o: extraction.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Extraction.dir/extraction.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Extraction.dir/extraction.cpp.o -c /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP/extraction.cpp

CMakeFiles/Extraction.dir/extraction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Extraction.dir/extraction.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP/extraction.cpp > CMakeFiles/Extraction.dir/extraction.cpp.i

CMakeFiles/Extraction.dir/extraction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Extraction.dir/extraction.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP/extraction.cpp -o CMakeFiles/Extraction.dir/extraction.cpp.s

CMakeFiles/Extraction.dir/extraction.cpp.o.requires:
.PHONY : CMakeFiles/Extraction.dir/extraction.cpp.o.requires

CMakeFiles/Extraction.dir/extraction.cpp.o.provides: CMakeFiles/Extraction.dir/extraction.cpp.o.requires
	$(MAKE) -f CMakeFiles/Extraction.dir/build.make CMakeFiles/Extraction.dir/extraction.cpp.o.provides.build
.PHONY : CMakeFiles/Extraction.dir/extraction.cpp.o.provides

CMakeFiles/Extraction.dir/extraction.cpp.o.provides.build: CMakeFiles/Extraction.dir/extraction.cpp.o

# Object files for target Extraction
Extraction_OBJECTS = \
"CMakeFiles/Extraction.dir/extraction.cpp.o"

# External object files for target Extraction
Extraction_EXTERNAL_OBJECTS =

Extraction: CMakeFiles/Extraction.dir/extraction.cpp.o
Extraction: CMakeFiles/Extraction.dir/build.make
Extraction: /usr/local/lib/libopencv_videostab.so.2.4.10
Extraction: /usr/local/lib/libopencv_video.so.2.4.10
Extraction: /usr/local/lib/libopencv_ts.a
Extraction: /usr/local/lib/libopencv_superres.so.2.4.10
Extraction: /usr/local/lib/libopencv_stitching.so.2.4.10
Extraction: /usr/local/lib/libopencv_photo.so.2.4.10
Extraction: /usr/local/lib/libopencv_ocl.so.2.4.10
Extraction: /usr/local/lib/libopencv_objdetect.so.2.4.10
Extraction: /usr/local/lib/libopencv_nonfree.so.2.4.10
Extraction: /usr/local/lib/libopencv_ml.so.2.4.10
Extraction: /usr/local/lib/libopencv_legacy.so.2.4.10
Extraction: /usr/local/lib/libopencv_imgproc.so.2.4.10
Extraction: /usr/local/lib/libopencv_highgui.so.2.4.10
Extraction: /usr/local/lib/libopencv_gpu.so.2.4.10
Extraction: /usr/local/lib/libopencv_flann.so.2.4.10
Extraction: /usr/local/lib/libopencv_features2d.so.2.4.10
Extraction: /usr/local/lib/libopencv_core.so.2.4.10
Extraction: /usr/local/lib/libopencv_contrib.so.2.4.10
Extraction: /usr/local/lib/libopencv_calib3d.so.2.4.10
Extraction: /usr/local/lib/libopencv_nonfree.so.2.4.10
Extraction: /usr/local/lib/libopencv_ocl.so.2.4.10
Extraction: /usr/local/lib/libopencv_gpu.so.2.4.10
Extraction: /usr/local/lib/libopencv_photo.so.2.4.10
Extraction: /usr/local/lib/libopencv_objdetect.so.2.4.10
Extraction: /usr/local/lib/libopencv_legacy.so.2.4.10
Extraction: /usr/local/lib/libopencv_video.so.2.4.10
Extraction: /usr/local/lib/libopencv_ml.so.2.4.10
Extraction: /usr/local/lib/libopencv_calib3d.so.2.4.10
Extraction: /usr/local/lib/libopencv_features2d.so.2.4.10
Extraction: /usr/local/lib/libopencv_highgui.so.2.4.10
Extraction: /usr/local/lib/libopencv_imgproc.so.2.4.10
Extraction: /usr/local/lib/libopencv_flann.so.2.4.10
Extraction: /usr/local/lib/libopencv_core.so.2.4.10
Extraction: CMakeFiles/Extraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Extraction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Extraction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Extraction.dir/build: Extraction
.PHONY : CMakeFiles/Extraction.dir/build

CMakeFiles/Extraction.dir/requires: CMakeFiles/Extraction.dir/extraction.cpp.o.requires
.PHONY : CMakeFiles/Extraction.dir/requires

CMakeFiles/Extraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Extraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Extraction.dir/clean

CMakeFiles/Extraction.dir/depend:
	cd /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP /home/colas/Programmation/M1INF1415/Image/Analyse/TP/1TP/CMakeFiles/Extraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Extraction.dir/depend

