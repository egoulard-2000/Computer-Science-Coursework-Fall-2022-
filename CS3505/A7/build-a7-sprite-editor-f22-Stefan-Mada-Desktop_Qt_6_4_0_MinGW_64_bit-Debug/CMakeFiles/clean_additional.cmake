# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SpriteEditor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SpriteEditor_autogen.dir\\ParseCache.txt"
  "SpriteEditor_autogen"
  )
endif()
