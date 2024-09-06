# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\utopia-terminal_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\utopia-terminal_autogen.dir\\ParseCache.txt"
  "utopia-terminal_autogen"
  )
endif()
