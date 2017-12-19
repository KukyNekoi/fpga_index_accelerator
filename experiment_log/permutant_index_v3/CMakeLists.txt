cmake_minimum_required(VERSION 3.8)
project(permutant_index)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c lib/dataset.c lib/dataset.h lib/element.c lib/element.h lib/index.c lib/index.h lib/permutant.c lib/permutant.h)
add_executable(untitled ${SOURCE_FILES})