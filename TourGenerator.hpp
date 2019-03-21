//
// Created by Ivan on 2019-03-20.
//

#ifndef GENETICALGORITHM_TOURGENERATOR_HPP
#define GENETICALGORITHM_TOURGENERATOR_HPP


#include <random>
#include "City.hpp"

class ` {
private:
    int CITIES_IN_TOUR;
    std::vector<City> masterList;
    std::string filename;
    std::default_random_engine static rng;

public:
    TourGenerator(std::string filename) : filename(filename){
            initiliazeCarList(filename);

            this->CITIES_IN_TOUR = this->masterList.size();
    }
    /**
     * initilize a list of cities from file
     * @param filepath
     */
    void initiliazeCarList(std::string filepath);

    void generateRandomTour();

};


#endif //GENETICALGORITHM_TOURGENERATOR_HPP
