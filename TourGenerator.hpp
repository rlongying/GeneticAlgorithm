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
    int CITIES_IN_TOUR;
    std::vector<City> masterList;
    std::vector<int> cityIndex;
    std::string filename;
    std::default_random_engine rng = std::default_random_engine{};;

    void initiliazeCarList(std::string filepath);

public:
    TourGenerator(std::string filename) : filename(filename) {
        initiliazeCarList(filename);

        this->CITIES_IN_TOUR = this->masterList.size();

        //initialize the index of city list
        for (int i = 0; i < CITIES_IN_TOUR; i++) {
            cityIndex.push_back(i);
        }
    }

    /**
     * initilize a list of cities from file
     * @param filepath
     */

    Tour generateRandomTour();

};


#endif //GENETICALGORITHM_TOURGENERATOR_HPP
