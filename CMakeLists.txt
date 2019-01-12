cmake_minimum_required(VERSION 3.12)
project(starwars2)

set(CMAKE_CXX_STANDARD 17)

add_executable(starwars2 main.cc rebelfleet.cc rebelfleet.h imperialfleet.cc battle.cc battle.h helper.cc helper.h)