//
// Created by Ivan on 2019-03-21.
//

#ifndef GENETICALGORITHM_GA_HPP
#define GENETICALGORITHM_GA_HPP


#include "Population.hpp"

class GA {

private:
    TourGenerator tourGenerator;
    Population population;
    double baseDistance;
    int count;
    double improvement;
    Tour baseRoute;

public:
    GA();

    void run();

    void report();

};


#endif //GENETICALGORITHM_GA_HPP
