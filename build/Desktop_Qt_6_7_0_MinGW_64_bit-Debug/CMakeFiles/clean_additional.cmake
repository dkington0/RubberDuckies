# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RubberDuckies_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RubberDuckies_autogen.dir\\ParseCache.txt"
  "RubberDuckies_autogen"
  )
endif()
