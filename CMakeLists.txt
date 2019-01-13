cmake_minimum_required(VERSION 3.12)
project(starwars22)

set(CMAKE_CXX_STANDARD 17)

add_executable(starwars22 main.cpp helper.cc helper.h rebelfleet.cc rebelfleet.h imperialfleet.cc imperialfleet.h battle.cc battle.h)