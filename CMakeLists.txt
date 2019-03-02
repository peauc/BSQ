project(BSQ)

cmake_minimum_required(VERSION 3.0)

file(GLOB_RECURSE SOURCE src/*.c)
file(GLOB_RECURSE INCLUDES include/*.h)

add_executable(bsq ${SOURCE} ${INCLUDES})
