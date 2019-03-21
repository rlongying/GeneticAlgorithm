//
// Created by Ivan on 2019-03-20.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP


#include <vector>
#include "Tour.hpp"

class Population {
private:
    std::vector<Tour> population;

public:

    void sort();

    void crossover(Tour& tour1, Tour& tour2);

    void crosses();

};


#endif //GENETICALGORITHM_POPULATION_HPP
