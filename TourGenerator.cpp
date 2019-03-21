//
// Created by Ivan on 2019-03-20.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include "TourGenerator.hpp"


void TourGenerator::initiliazeCarList(std::string filepath) {
    std::string line;
    std::ifstream in(filepath);

    std::string cityName;
    int cityX;
    int cityY;

    while(in >> cityName >> cityX >> cityY){
        this->masterList.push_back(City(cityName, cityX, cityY));
    }

}

Tour TourGenerator::generateRandomTour() {

    std::shuffle(cityIndex.begin(), cityIndex.end(), rng);

    std::vector<City *> cityList;
    for (int i = 0; i < masterList.size(); i ++) {
        cityList.push_back(&masterList[cityIndex[i]]);
    }

    return Tour{cityList};
}