file(REMOVE_RECURSE
  "bootloader/bootloader.bin"
  "bootloader/bootloader.elf"
  "bootloader/bootloader.map"
  "ccs811.bin"
  "ccs811.map"
  "config/sdkconfig.cmake"
  "config/sdkconfig.h"
  "flash_project_args"
  "project_elf_src_esp32.c"
  "CMakeFiles/ccs811.elf.dir/project_elf_src_esp32.c.obj"
  "ccs811.elf"
  "ccs811.elf.pdb"
  "project_elf_src_esp32.c"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/ccs811.elf.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
