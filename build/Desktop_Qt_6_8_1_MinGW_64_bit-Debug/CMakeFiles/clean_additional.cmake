# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ville_virtuelle_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ville_virtuelle_autogen.dir\\ParseCache.txt"
  "ville_virtuelle_autogen"
  )
endif()
