//
// Created by Ivan on 2019-03-19.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP


#include <vector>
#include "City.hpp"

class Tour {

private:
    int CITIES_IN_TOUR = 32;
    std::vector<City> carList;

public:
    /**
     * initilize a list of cities from file
     * @param filepath
     */
    void initiliazeCarList(std::string filepath);
};


#endif //GENETICALGORITHM_TOUR_HPP
