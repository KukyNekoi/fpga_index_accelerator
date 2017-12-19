cmake_minimum_required(VERSION 3.4)
project(MetricHashing)

#include SDL2 libraries :3
INCLUDE(FindPkgConfig)

FIND_LIBRARY(LIBSTDCXX NAMES stdc++)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

### START OF SOURCE FILES ###
#FLAGS AND MACROS
LIST(APPEND SOURCE_FILES lib/etc/Flags.h lib/etc/Macros.h)

#LOG TOOLS
LIST(APPEND SOURCE_FILES lib/log/Log.cpp lib/log/Log.h)

#OBJECTS FOR INDEXING
LIST(APPEND SOURCE_FILES lib/element/Element.h)
LIST(APPEND SOURCE_FILES lib/element/Vectorelement.cpp lib/element/Vectorelement.h)

#PERMUTATION OBJECTS
LIST(APPEND SOURCE_FILES lib/permutation/Permutation.cpp lib/permutation/Permutation.h)

#VISUALIZATION TOOLS
LIST(APPEND SOURCE_FILES lib/visualization/Screen.cpp lib/visualization/Screen.h)

#INDICES
LIST(APPEND SOURCE_FILES lib/indices/Index.h)
LIST(APPEND SOURCE_FILES lib/indices/StandardPermutationIndex.cpp lib/indices/StandardPermutationIndex.h)
LIST(APPEND SOURCE_FILES lib/indices/HashedPermutationIndex.cpp lib/indices/HashedPermutationIndex.h)

#EXPERIMENTATION TOOLS
LIST(APPEND SOURCE_FILES lib/canned_food/Experiment.cpp lib/canned_food/Experiment.h)

#MAIN
LIST(APPEND SOURCE_FILES main.cpp)
#### END OF SOURCE FILES ####

#ADD_COMPILE_OPTIONS(-stdlib=libstdc++)
ADD_COMPILE_OPTIONS(-std=gnu++14)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")
SET(CMAKE_C_COMPILER /usr/local/bin/gcc-7)
SET(CMAKE_CXX_COMPILER /usr/local/bin/g++-7)
set( CMAKE_VERBOSE_MAKEFILE on )

add_executable(MetricHashing ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${LIBSTDCXX} ${SDL2_LIBRARIES})
