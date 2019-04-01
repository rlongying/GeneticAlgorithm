//
// Created by Ivan on 2019-03-21.
//

#ifndef GENETICALGORITHM_CONSTANTS_HPP
#define GENETICALGORITHM_CONSTANTS_HPP

typedef std::chrono::high_resolution_clock myclock;

static const myclock::time_point BEGINING_TIME = myclock::now();

static const int CITIES_IN_TOUR = 32;
static const int POPULATION_SIZE = 64;
static const int SUFFLES = 64;
static const int ITERATIONS = 1000;
static const int MAP_BOUNDARY = 1000;
static const int PARENT_POOL_SIZE = 5;
static const double MUTATION_RATE = 0.15;
static const long SCALE_FACTOR = 1000000;
static const double IMPROVEMENT_RATE = 0.35;

#endif //GENETICALGORITHM_CONSTANTS_HPP
