//
// Created by Ivan on 2019-03-20.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include "TourGenerator.hpp"

std::default_random_engine TourGenerator::rng = std::default_random_engine {};

void TourGenerator::initiliazeCarList(std::string filepath) {
    std::string line;
    std::ifstream in(filepath);

//        while (std::getline(in, line)) {
//            std::istringstream iss(line);
//
    std::string cityName;
    int cityX;
    int cityY;
//
//
//
//        }
    while(in >> cityName >> cityX >> cityY){
        std::cout << cityName << ", " << cityX << ", " << cityY << std::endl;
        this->masterList.push_back(City(cityName, cityX, cityY));
    }

}

void TourGenerator::generateRandomTour() {

    std::shuffle(masterList.begin(), masterList.end(), rng);


}