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
CMAKE_SOURCE_DIR = /home/ubuntu/esp/esp-idf/components/bootloader/subproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ESP_IOT/sensor/as3935/src/build/bootloader

# Utility rule file for confserver.

# Include the progress variables for this target.
include CMakeFiles/confserver.dir/progress.make

CMakeFiles/confserver:
	/home/ubuntu/.espressif/python_env/idf5.0_py3.8_env/bin/python /home/ubuntu/esp/esp-idf/tools/kconfig_new/prepare_kconfig_files.py --list-separator=semicolon --env-file /home/ubuntu/ESP_IOT/sensor/as3935/src/build/bootloader/config.env
	/home/ubuntu/.espressif/python_env/idf5.0_py3.8_env/bin/python /home/ubuntu/esp/esp-idf/tools/kconfig_new/confserver.py --env-file /home/ubuntu/ESP_IOT/sensor/as3935/src/build/bootloader/config.env --kconfig /home/ubuntu/esp/esp-idf/Kconfig --sdkconfig-rename /home/ubuntu/esp/esp-idf/sdkconfig.rename --config /home/ubuntu/ESP_IOT/sensor/as3935/src/sdkconfig

confserver: CMakeFiles/confserver
confserver: CMakeFiles/confserver.dir/build.make

.PHONY : confserver

# Rule to build all files generated by this target.
CMakeFiles/confserver.dir/build: confserver

.PHONY : CMakeFiles/confserver.dir/build

CMakeFiles/confserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/confserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/confserver.dir/clean

CMakeFiles/confserver.dir/depend:
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/bootloader && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/esp/esp-idf/components/bootloader/subproject /home/ubuntu/esp/esp-idf/components/bootloader/subproject /home/ubuntu/ESP_IOT/sensor/as3935/src/build/bootloader /home/ubuntu/ESP_IOT/sensor/as3935/src/build/bootloader /home/ubuntu/ESP_IOT/sensor/as3935/src/build/bootloader/CMakeFiles/confserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/confserver.dir/depend

