# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\TeslaGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TeslaGame_autogen.dir\\ParseCache.txt"
  "TeslaGame_autogen"
  )
endif()
