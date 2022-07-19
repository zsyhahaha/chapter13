cmake_minimum_required(VERSION 3.22)
project(chapter13)

set(CMAKE_CXX_STANDARD 14)

add_executable(chapter13 dma.cpp dma.h usedma.cpp Port.cpp Port.h)
