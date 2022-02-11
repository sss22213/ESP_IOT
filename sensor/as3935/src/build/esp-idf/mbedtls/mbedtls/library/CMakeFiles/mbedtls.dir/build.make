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
CMAKE_SOURCE_DIR = /home/ubuntu/ESP_IOT/sensor/as3935/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ESP_IOT/sensor/as3935/src/build

# Include any dependencies generated for this target.
include esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/depend.make

# Include the progress variables for this target.
include esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/debug.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/debug.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/debug.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/debug.c > CMakeFiles/mbedtls.dir/debug.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/debug.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/debug.c -o CMakeFiles/mbedtls.dir/debug.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cache.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/ssl_cache.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cache.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_cache.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cache.c > CMakeFiles/mbedtls.dir/ssl_cache.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_cache.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cache.c -o CMakeFiles/mbedtls.dir/ssl_cache.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ciphersuites.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ciphersuites.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ciphersuites.c > CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ciphersuites.c -o CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cli.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/ssl_cli.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cli.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_cli.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cli.c > CMakeFiles/mbedtls.dir/ssl_cli.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_cli.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cli.c -o CMakeFiles/mbedtls.dir/ssl_cli.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cookie.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/ssl_cookie.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cookie.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_cookie.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cookie.c > CMakeFiles/mbedtls.dir/ssl_cookie.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_cookie.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_cookie.c -o CMakeFiles/mbedtls.dir/ssl_cookie.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_srv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/ssl_srv.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_srv.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_srv.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_srv.c > CMakeFiles/mbedtls.dir/ssl_srv.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_srv.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_srv.c -o CMakeFiles/mbedtls.dir/ssl_srv.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ticket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/ssl_ticket.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ticket.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_ticket.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ticket.c > CMakeFiles/mbedtls.dir/ssl_ticket.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_ticket.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_ticket.c -o CMakeFiles/mbedtls.dir/ssl_ticket.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_tls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/ssl_tls.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_tls.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/ssl_tls.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_tls.c > CMakeFiles/mbedtls.dir/ssl_tls.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/ssl_tls.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library/ssl_tls.c -o CMakeFiles/mbedtls.dir/ssl_tls.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/port/mbedtls_debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/port/mbedtls_debug.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/port/mbedtls_debug.c > CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/port/mbedtls_debug.c -o CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.s

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.obj: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/flags.make
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.obj: /home/ubuntu/esp/esp-idf/components/mbedtls/port/net_sockets.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.obj"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.obj   -c /home/ubuntu/esp/esp-idf/components/mbedtls/port/net_sockets.c

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.i"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/esp/esp-idf/components/mbedtls/port/net_sockets.c > CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.i

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.s"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && /home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/esp/esp-idf/components/mbedtls/port/net_sockets.c -o CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.s

# Object files for target mbedtls
mbedtls_OBJECTS = \
"CMakeFiles/mbedtls.dir/debug.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_cache.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_cli.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_cookie.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_srv.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_ticket.c.obj" \
"CMakeFiles/mbedtls.dir/ssl_tls.c.obj" \
"CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.obj" \
"CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.obj"

# External object files for target mbedtls
mbedtls_EXTERNAL_OBJECTS =

esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/debug.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cache.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ciphersuites.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cli.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_cookie.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_srv.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_ticket.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/ssl_tls.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/mbedtls_debug.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/__/__/port/net_sockets.c.obj
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/build.make
esp-idf/mbedtls/mbedtls/library/libmbedtls.a: esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ESP_IOT/sensor/as3935/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library libmbedtls.a"
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && $(CMAKE_COMMAND) -P CMakeFiles/mbedtls.dir/cmake_clean_target.cmake
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mbedtls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/build: esp-idf/mbedtls/mbedtls/library/libmbedtls.a

.PHONY : esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/build

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/clean:
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library && $(CMAKE_COMMAND) -P CMakeFiles/mbedtls.dir/cmake_clean.cmake
.PHONY : esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/clean

esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/depend:
	cd /home/ubuntu/ESP_IOT/sensor/as3935/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ESP_IOT/sensor/as3935/src /home/ubuntu/esp/esp-idf/components/mbedtls/mbedtls/library /home/ubuntu/ESP_IOT/sensor/as3935/src/build /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library /home/ubuntu/ESP_IOT/sensor/as3935/src/build/esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/mbedtls/mbedtls/library/CMakeFiles/mbedtls.dir/depend

