//
// Created by Ivan on 2019-03-20.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include "TourGenerator.hpp"


void TourGenerator::initiliazeCarList() {
    std::uniform_int_distribution<int> generator(0, 1000);

    std::string cityName;
    int cityX;
    int cityY;

    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        cityName = "city" + std::to_string(i);
        cityX = generator(rng);
        cityY = generator(rng);
        masterList.emplace_back(cityName, cityX, cityY);
    }
    //read sample data from file for test
//    std::string line;
//    std::ifstream in("../cities.txt");
//
//    std::string cityName;
//    int cityX;
//    int cityY;
//
//    while(in >> cityName >> cityX >> cityY){
//        masterList.push_back(City(cityName, cityX, cityY));
//    }

}

Tour TourGenerator::generateRandomTour() {

    std::shuffle(cityIndex.begin(), cityIndex.end(), rng);

    std::vector<City *> cityList;
    for (int i = 0; i < CITIES_IN_TOUR; i ++) {
        cityList.push_back(&masterList[cityIndex[i]]);
    }

    return Tour{cityList};
}

TourGenerator::TourGenerator() {

    //create masterlist
    initiliazeCarList();
    //initialize the index of city list
    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        cityIndex.push_back(i);
    }
}
