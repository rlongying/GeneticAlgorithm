//
// Created by Ivan on 2019-03-19.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP


#include <vector>
#include "City.hpp"

class Tour {

private:
    std::vector<City *> cityList;
    double fitness;

public:
    Tour(std::vector<City *> list) : cityList(list){

    }

};


#endif //GENETICALGORITHM_TOUR_HPP
