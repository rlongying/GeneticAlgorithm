cmake_minimum_required(VERSION 3.13)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticAlgorithm main.cpp City.cpp City.hpp Tour.cpp Tour.hpp TourGenerator.cpp TourGenerator.hpp Population.cpp Population.hpp Constants.hpp GA.cpp GA.hpp)