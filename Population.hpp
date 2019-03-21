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

    /**
     * sort the population in ascending order by the fitness level of each tour
     */
    void sort();

    /**
     * get a new tour by crossing two parents randomly selected
     * @param tour1 parent 1
     * @param tour2 parent 2
     */
    Tour crossover(Tour& tour1, Tour& tour2);

    /**
     * cross the tours in the populations
     */
    void crosses();

    /**
     * return a tour
     * @param index the position of the target tour in the population
     * @return an instance of tour
     */
    Tour getTour(int index) const {return population[index];}

};


#endif //GENETICALGORITHM_POPULATION_HPP
