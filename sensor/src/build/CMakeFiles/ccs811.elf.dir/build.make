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
CMAKE_SOURCE_DIR = /home/ubuntu/ESP_IOT/sensor/CCS811/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ESP_IOT/sensor/CCS811/src/build

# Include any dependencies generated for this target.
include CMakeFiles/ccs811.elf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ccs811.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ccs811.elf.dir/flags.make

project_elf_src_esp32.c:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/ESP_IOT/sensor/CCS811/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating project_elf_src_esp32.c"
	/usr/bin/cmake -E touch /home/ubuntu/ESP_IOT/sensor/CCS811/src/build/project_elf_src_esp32.c

CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.obj: CMakeFiles/ccs811.elf.dir/flags.make
CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.obj: project_elf_src_esp32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ESP_IOT/sensor/CCS811/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.obj"
	/home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.obj   -c /home/ubuntu/ESP_IOT/sensor/CCS811/src/build/project_elf_src_esp32.c

CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.i"
	/home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/ESP_IOT/sensor/CCS811/src/build/project_elf_src_esp32.c > CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.i

CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.s"
	/home/ubuntu/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/ESP_IOT/sensor/CCS811/src/build/project_elf_src_esp32.c -o CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.s

# Object files for target ccs811.elf
ccs811_elf_OBJECTS = \
"CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.obj"

# External object files for target ccs811.elf
ccs811_elf_EXTERNAL_OBJECTS =

ccs811.elf: CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.obj
ccs811.elf: CMakeFiles/ccs811.elf.dir/build.make
ccs811.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ccs811.elf: esp-idf/efuse/libefuse.a
ccs811.elf: esp-idf/driver/libdriver.a
ccs811.elf: esp-idf/esp_pm/libesp_pm.a
ccs811.elf: esp-idf/mbedtls/libmbedtls.a
ccs811.elf: esp-idf/app_update/libapp_update.a
ccs811.elf: esp-idf/bootloader_support/libbootloader_support.a
ccs811.elf: esp-idf/spi_flash/libspi_flash.a
ccs811.elf: esp-idf/nvs_flash/libnvs_flash.a
ccs811.elf: esp-idf/pthread/libpthread.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: esp-idf/esp_system/libesp_system.a
ccs811.elf: esp-idf/esp_rom/libesp_rom.a
ccs811.elf: esp-idf/hal/libhal.a
ccs811.elf: esp-idf/vfs/libvfs.a
ccs811.elf: esp-idf/esp_eth/libesp_eth.a
ccs811.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
ccs811.elf: esp-idf/esp_netif/libesp_netif.a
ccs811.elf: esp-idf/esp_event/libesp_event.a
ccs811.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ccs811.elf: esp-idf/esp_wifi/libesp_wifi.a
ccs811.elf: esp-idf/lwip/liblwip.a
ccs811.elf: esp-idf/log/liblog.a
ccs811.elf: esp-idf/heap/libheap.a
ccs811.elf: esp-idf/soc/libsoc.a
ccs811.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ccs811.elf: esp-idf/xtensa/libxtensa.a
ccs811.elf: esp-idf/esp_common/libesp_common.a
ccs811.elf: esp-idf/esp_timer/libesp_timer.a
ccs811.elf: esp-idf/freertos/libfreertos.a
ccs811.elf: esp-idf/newlib/libnewlib.a
ccs811.elf: esp-idf/cxx/libcxx.a
ccs811.elf: esp-idf/app_trace/libapp_trace.a
ccs811.elf: esp-idf/asio/libasio.a
ccs811.elf: esp-idf/unity/libunity.a
ccs811.elf: esp-idf/cmock/libcmock.a
ccs811.elf: esp-idf/coap/libcoap.a
ccs811.elf: esp-idf/console/libconsole.a
ccs811.elf: esp-idf/http_parser/libhttp_parser.a
ccs811.elf: esp-idf/esp-tls/libesp-tls.a
ccs811.elf: esp-idf/esp_adc_cal/libesp_adc_cal.a
ccs811.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ccs811.elf: esp-idf/esp_hid/libesp_hid.a
ccs811.elf: esp-idf/tcp_transport/libtcp_transport.a
ccs811.elf: esp-idf/esp_http_client/libesp_http_client.a
ccs811.elf: esp-idf/esp_http_server/libesp_http_server.a
ccs811.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ccs811.elf: esp-idf/esp_lcd/libesp_lcd.a
ccs811.elf: esp-idf/protobuf-c/libprotobuf-c.a
ccs811.elf: esp-idf/protocomm/libprotocomm.a
ccs811.elf: esp-idf/mdns/libmdns.a
ccs811.elf: esp-idf/esp_local_ctrl/libesp_local_ctrl.a
ccs811.elf: esp-idf/sdmmc/libsdmmc.a
ccs811.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
ccs811.elf: esp-idf/esp_websocket_client/libesp_websocket_client.a
ccs811.elf: esp-idf/espcoredump/libespcoredump.a
ccs811.elf: esp-idf/wear_levelling/libwear_levelling.a
ccs811.elf: esp-idf/fatfs/libfatfs.a
ccs811.elf: esp-idf/freemodbus/libfreemodbus.a
ccs811.elf: esp-idf/json/libjson.a
ccs811.elf: esp-idf/mqtt/libmqtt.a
ccs811.elf: esp-idf/openssl/libopenssl.a
ccs811.elf: esp-idf/perfmon/libperfmon.a
ccs811.elf: esp-idf/spiffs/libspiffs.a
ccs811.elf: esp-idf/ulp/libulp.a
ccs811.elf: esp-idf/wifi_provisioning/libwifi_provisioning.a
ccs811.elf: esp-idf/main/libmain.a
ccs811.elf: esp-idf/app_trace/libapp_trace.a
ccs811.elf: esp-idf/app_trace/libapp_trace.a
ccs811.elf: esp-idf/app_trace/libapp_trace.a
ccs811.elf: esp-idf/asio/libasio.a
ccs811.elf: esp-idf/cmock/libcmock.a
ccs811.elf: esp-idf/unity/libunity.a
ccs811.elf: esp-idf/coap/libcoap.a
ccs811.elf: esp-idf/esp_adc_cal/libesp_adc_cal.a
ccs811.elf: esp-idf/esp_gdbstub/libesp_gdbstub.a
ccs811.elf: esp-idf/esp_hid/libesp_hid.a
ccs811.elf: esp-idf/esp_lcd/libesp_lcd.a
ccs811.elf: esp-idf/esp_local_ctrl/libesp_local_ctrl.a
ccs811.elf: esp-idf/esp_websocket_client/libesp_websocket_client.a
ccs811.elf: esp-idf/espcoredump/libespcoredump.a
ccs811.elf: esp-idf/fatfs/libfatfs.a
ccs811.elf: esp-idf/wear_levelling/libwear_levelling.a
ccs811.elf: esp-idf/freemodbus/libfreemodbus.a
ccs811.elf: esp-idf/mqtt/libmqtt.a
ccs811.elf: esp-idf/openssl/libopenssl.a
ccs811.elf: esp-idf/perfmon/libperfmon.a
ccs811.elf: esp-idf/spiffs/libspiffs.a
ccs811.elf: esp-idf/wifi_provisioning/libwifi_provisioning.a
ccs811.elf: esp-idf/protocomm/libprotocomm.a
ccs811.elf: esp-idf/protobuf-c/libprotobuf-c.a
ccs811.elf: esp-idf/mdns/libmdns.a
ccs811.elf: esp-idf/console/libconsole.a
ccs811.elf: esp-idf/json/libjson.a
ccs811.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ccs811.elf: esp-idf/efuse/libefuse.a
ccs811.elf: esp-idf/driver/libdriver.a
ccs811.elf: esp-idf/esp_pm/libesp_pm.a
ccs811.elf: esp-idf/mbedtls/libmbedtls.a
ccs811.elf: esp-idf/app_update/libapp_update.a
ccs811.elf: esp-idf/bootloader_support/libbootloader_support.a
ccs811.elf: esp-idf/spi_flash/libspi_flash.a
ccs811.elf: esp-idf/nvs_flash/libnvs_flash.a
ccs811.elf: esp-idf/pthread/libpthread.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: esp-idf/esp_system/libesp_system.a
ccs811.elf: esp-idf/esp_rom/libesp_rom.a
ccs811.elf: esp-idf/hal/libhal.a
ccs811.elf: esp-idf/vfs/libvfs.a
ccs811.elf: esp-idf/esp_eth/libesp_eth.a
ccs811.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
ccs811.elf: esp-idf/esp_netif/libesp_netif.a
ccs811.elf: esp-idf/esp_event/libesp_event.a
ccs811.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ccs811.elf: esp-idf/esp_wifi/libesp_wifi.a
ccs811.elf: esp-idf/lwip/liblwip.a
ccs811.elf: esp-idf/log/liblog.a
ccs811.elf: esp-idf/heap/libheap.a
ccs811.elf: esp-idf/soc/libsoc.a
ccs811.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ccs811.elf: esp-idf/xtensa/libxtensa.a
ccs811.elf: esp-idf/esp_common/libesp_common.a
ccs811.elf: esp-idf/esp_timer/libesp_timer.a
ccs811.elf: esp-idf/freertos/libfreertos.a
ccs811.elf: esp-idf/newlib/libnewlib.a
ccs811.elf: esp-idf/cxx/libcxx.a
ccs811.elf: esp-idf/http_parser/libhttp_parser.a
ccs811.elf: esp-idf/esp-tls/libesp-tls.a
ccs811.elf: esp-idf/tcp_transport/libtcp_transport.a
ccs811.elf: esp-idf/esp_http_client/libesp_http_client.a
ccs811.elf: esp-idf/esp_http_server/libesp_http_server.a
ccs811.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ccs811.elf: esp-idf/sdmmc/libsdmmc.a
ccs811.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
ccs811.elf: esp-idf/ulp/libulp.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ccs811.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ccs811.elf: esp-idf/efuse/libefuse.a
ccs811.elf: esp-idf/driver/libdriver.a
ccs811.elf: esp-idf/esp_pm/libesp_pm.a
ccs811.elf: esp-idf/mbedtls/libmbedtls.a
ccs811.elf: esp-idf/app_update/libapp_update.a
ccs811.elf: esp-idf/bootloader_support/libbootloader_support.a
ccs811.elf: esp-idf/spi_flash/libspi_flash.a
ccs811.elf: esp-idf/nvs_flash/libnvs_flash.a
ccs811.elf: esp-idf/pthread/libpthread.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: esp-idf/esp_system/libesp_system.a
ccs811.elf: esp-idf/esp_rom/libesp_rom.a
ccs811.elf: esp-idf/hal/libhal.a
ccs811.elf: esp-idf/vfs/libvfs.a
ccs811.elf: esp-idf/esp_eth/libesp_eth.a
ccs811.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
ccs811.elf: esp-idf/esp_netif/libesp_netif.a
ccs811.elf: esp-idf/esp_event/libesp_event.a
ccs811.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ccs811.elf: esp-idf/esp_wifi/libesp_wifi.a
ccs811.elf: esp-idf/lwip/liblwip.a
ccs811.elf: esp-idf/log/liblog.a
ccs811.elf: esp-idf/heap/libheap.a
ccs811.elf: esp-idf/soc/libsoc.a
ccs811.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ccs811.elf: esp-idf/xtensa/libxtensa.a
ccs811.elf: esp-idf/esp_common/libesp_common.a
ccs811.elf: esp-idf/esp_timer/libesp_timer.a
ccs811.elf: esp-idf/freertos/libfreertos.a
ccs811.elf: esp-idf/newlib/libnewlib.a
ccs811.elf: esp-idf/cxx/libcxx.a
ccs811.elf: esp-idf/http_parser/libhttp_parser.a
ccs811.elf: esp-idf/esp-tls/libesp-tls.a
ccs811.elf: esp-idf/tcp_transport/libtcp_transport.a
ccs811.elf: esp-idf/esp_http_client/libesp_http_client.a
ccs811.elf: esp-idf/esp_http_server/libesp_http_server.a
ccs811.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ccs811.elf: esp-idf/sdmmc/libsdmmc.a
ccs811.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
ccs811.elf: esp-idf/ulp/libulp.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ccs811.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ccs811.elf: esp-idf/efuse/libefuse.a
ccs811.elf: esp-idf/driver/libdriver.a
ccs811.elf: esp-idf/esp_pm/libesp_pm.a
ccs811.elf: esp-idf/mbedtls/libmbedtls.a
ccs811.elf: esp-idf/app_update/libapp_update.a
ccs811.elf: esp-idf/bootloader_support/libbootloader_support.a
ccs811.elf: esp-idf/spi_flash/libspi_flash.a
ccs811.elf: esp-idf/nvs_flash/libnvs_flash.a
ccs811.elf: esp-idf/pthread/libpthread.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: esp-idf/esp_system/libesp_system.a
ccs811.elf: esp-idf/esp_rom/libesp_rom.a
ccs811.elf: esp-idf/hal/libhal.a
ccs811.elf: esp-idf/vfs/libvfs.a
ccs811.elf: esp-idf/esp_eth/libesp_eth.a
ccs811.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
ccs811.elf: esp-idf/esp_netif/libesp_netif.a
ccs811.elf: esp-idf/esp_event/libesp_event.a
ccs811.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ccs811.elf: esp-idf/esp_wifi/libesp_wifi.a
ccs811.elf: esp-idf/lwip/liblwip.a
ccs811.elf: esp-idf/log/liblog.a
ccs811.elf: esp-idf/heap/libheap.a
ccs811.elf: esp-idf/soc/libsoc.a
ccs811.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ccs811.elf: esp-idf/xtensa/libxtensa.a
ccs811.elf: esp-idf/esp_common/libesp_common.a
ccs811.elf: esp-idf/esp_timer/libesp_timer.a
ccs811.elf: esp-idf/freertos/libfreertos.a
ccs811.elf: esp-idf/newlib/libnewlib.a
ccs811.elf: esp-idf/cxx/libcxx.a
ccs811.elf: esp-idf/http_parser/libhttp_parser.a
ccs811.elf: esp-idf/esp-tls/libesp-tls.a
ccs811.elf: esp-idf/tcp_transport/libtcp_transport.a
ccs811.elf: esp-idf/esp_http_client/libesp_http_client.a
ccs811.elf: esp-idf/esp_http_server/libesp_http_server.a
ccs811.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ccs811.elf: esp-idf/sdmmc/libsdmmc.a
ccs811.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
ccs811.elf: esp-idf/ulp/libulp.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ccs811.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ccs811.elf: esp-idf/efuse/libefuse.a
ccs811.elf: esp-idf/driver/libdriver.a
ccs811.elf: esp-idf/esp_pm/libesp_pm.a
ccs811.elf: esp-idf/mbedtls/libmbedtls.a
ccs811.elf: esp-idf/app_update/libapp_update.a
ccs811.elf: esp-idf/bootloader_support/libbootloader_support.a
ccs811.elf: esp-idf/spi_flash/libspi_flash.a
ccs811.elf: esp-idf/nvs_flash/libnvs_flash.a
ccs811.elf: esp-idf/pthread/libpthread.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: esp-idf/esp_system/libesp_system.a
ccs811.elf: esp-idf/esp_rom/libesp_rom.a
ccs811.elf: esp-idf/hal/libhal.a
ccs811.elf: esp-idf/vfs/libvfs.a
ccs811.elf: esp-idf/esp_eth/libesp_eth.a
ccs811.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
ccs811.elf: esp-idf/esp_netif/libesp_netif.a
ccs811.elf: esp-idf/esp_event/libesp_event.a
ccs811.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ccs811.elf: esp-idf/esp_wifi/libesp_wifi.a
ccs811.elf: esp-idf/lwip/liblwip.a
ccs811.elf: esp-idf/log/liblog.a
ccs811.elf: esp-idf/heap/libheap.a
ccs811.elf: esp-idf/soc/libsoc.a
ccs811.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ccs811.elf: esp-idf/xtensa/libxtensa.a
ccs811.elf: esp-idf/esp_common/libesp_common.a
ccs811.elf: esp-idf/esp_timer/libesp_timer.a
ccs811.elf: esp-idf/freertos/libfreertos.a
ccs811.elf: esp-idf/newlib/libnewlib.a
ccs811.elf: esp-idf/cxx/libcxx.a
ccs811.elf: esp-idf/http_parser/libhttp_parser.a
ccs811.elf: esp-idf/esp-tls/libesp-tls.a
ccs811.elf: esp-idf/tcp_transport/libtcp_transport.a
ccs811.elf: esp-idf/esp_http_client/libesp_http_client.a
ccs811.elf: esp-idf/esp_http_server/libesp_http_server.a
ccs811.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ccs811.elf: esp-idf/sdmmc/libsdmmc.a
ccs811.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
ccs811.elf: esp-idf/ulp/libulp.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ccs811.elf: esp-idf/esp_ringbuf/libesp_ringbuf.a
ccs811.elf: esp-idf/efuse/libefuse.a
ccs811.elf: esp-idf/driver/libdriver.a
ccs811.elf: esp-idf/esp_pm/libesp_pm.a
ccs811.elf: esp-idf/mbedtls/libmbedtls.a
ccs811.elf: esp-idf/app_update/libapp_update.a
ccs811.elf: esp-idf/bootloader_support/libbootloader_support.a
ccs811.elf: esp-idf/spi_flash/libspi_flash.a
ccs811.elf: esp-idf/nvs_flash/libnvs_flash.a
ccs811.elf: esp-idf/pthread/libpthread.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: esp-idf/esp_system/libesp_system.a
ccs811.elf: esp-idf/esp_rom/libesp_rom.a
ccs811.elf: esp-idf/hal/libhal.a
ccs811.elf: esp-idf/vfs/libvfs.a
ccs811.elf: esp-idf/esp_eth/libesp_eth.a
ccs811.elf: esp-idf/tcpip_adapter/libtcpip_adapter.a
ccs811.elf: esp-idf/esp_netif/libesp_netif.a
ccs811.elf: esp-idf/esp_event/libesp_event.a
ccs811.elf: esp-idf/wpa_supplicant/libwpa_supplicant.a
ccs811.elf: esp-idf/esp_wifi/libesp_wifi.a
ccs811.elf: esp-idf/lwip/liblwip.a
ccs811.elf: esp-idf/log/liblog.a
ccs811.elf: esp-idf/heap/libheap.a
ccs811.elf: esp-idf/soc/libsoc.a
ccs811.elf: esp-idf/esp_hw_support/libesp_hw_support.a
ccs811.elf: esp-idf/xtensa/libxtensa.a
ccs811.elf: esp-idf/esp_common/libesp_common.a
ccs811.elf: esp-idf/esp_timer/libesp_timer.a
ccs811.elf: esp-idf/freertos/libfreertos.a
ccs811.elf: esp-idf/newlib/libnewlib.a
ccs811.elf: esp-idf/cxx/libcxx.a
ccs811.elf: esp-idf/http_parser/libhttp_parser.a
ccs811.elf: esp-idf/esp-tls/libesp-tls.a
ccs811.elf: esp-idf/tcp_transport/libtcp_transport.a
ccs811.elf: esp-idf/esp_http_client/libesp_http_client.a
ccs811.elf: esp-idf/esp_http_server/libesp_http_server.a
ccs811.elf: esp-idf/esp_https_ota/libesp_https_ota.a
ccs811.elf: esp-idf/sdmmc/libsdmmc.a
ccs811.elf: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a
ccs811.elf: esp-idf/ulp/libulp.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedtls.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedcrypto.a
ccs811.elf: esp-idf/mbedtls/mbedtls/library/libmbedx509.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcoexist.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libcore.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libespnow.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libmesh.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libnet80211.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libpp.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libsmartconfig.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_wifi/lib/esp32/libwapi.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: esp-idf/esp_phy/libesp_phy.a
ccs811.elf: /home/ubuntu/esp/esp-idf/components/xtensa/esp32/libxt_hal.a
ccs811.elf: esp-idf/newlib/libnewlib.a
ccs811.elf: esp-idf/pthread/libpthread.a
ccs811.elf: esp-idf/cxx/libcxx.a
ccs811.elf: esp-idf/esp_system/ld/memory.ld
ccs811.elf: esp-idf/esp_system/ld/sections.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.api.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.libgcc.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-data.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.syscalls.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-funcs.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/esp_rom/esp32/ld/esp32.rom.newlib-time.ld
ccs811.elf: /home/ubuntu/esp/esp-idf/components/soc/esp32/ld/esp32.peripherals.ld
ccs811.elf: CMakeFiles/ccs811.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ESP_IOT/sensor/CCS811/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ccs811.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ccs811.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ccs811.elf.dir/build: ccs811.elf

.PHONY : CMakeFiles/ccs811.elf.dir/build

CMakeFiles/ccs811.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ccs811.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ccs811.elf.dir/clean

CMakeFiles/ccs811.elf.dir/depend: project_elf_src_esp32.c
	cd /home/ubuntu/ESP_IOT/sensor/CCS811/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ESP_IOT/sensor/CCS811/src /home/ubuntu/ESP_IOT/sensor/CCS811/src /home/ubuntu/ESP_IOT/sensor/CCS811/src/build /home/ubuntu/ESP_IOT/sensor/CCS811/src/build /home/ubuntu/ESP_IOT/sensor/CCS811/src/build/CMakeFiles/ccs811.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ccs811.elf.dir/depend

