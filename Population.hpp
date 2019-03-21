//
// Created by Ivan on 2019-03-20.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP


#include <vector>
#include "Tour.hpp"
#include "TourGenerator.hpp"

class Population {
private:
    std::vector<Tour> population;
    int populationSize;
    TourGenerator generator;

public:


    Population(int size, TourGenerator& generator);

    void sort();

    void crossover(Tour& tour1, Tour& tour2);

    void crosses();

    Tour getTour(int index) const {return population[index];}

};


#endif //GENETICALGORITHM_POPULATION_HPP
