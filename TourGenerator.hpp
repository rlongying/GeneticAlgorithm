//
// Created by Ivan on 2019-03-20.
//

#ifndef GENETICALGORITHM_TOURGENERATOR_HPP
#define GENETICALGORITHM_TOURGENERATOR_HPP


#include <random>
#include "City.hpp"
#include "Tour.hpp"

class TourGenerator {
private:
    std::vector<City> masterList;
    std::vector<int> cityIndex;
    myclock::duration d = myclock::now() - BEGINING_TIME;
    std::default_random_engine rng = std::default_random_engine(d.count());;

    void initiliazeCarList();

public:
    TourGenerator();

    /**
     * initilize a list of cities from file
     * @param filepath
     */

    Tour generateRandomTour();

};


#endif //GENETICALGORITHM_TOURGENERATOR_HPP
