//
// Created by Ivan on 2019-03-19.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include "Tour.hpp"

void Tour::initiliazeCarList(std::string filepath) {
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
            this->carList.push_back(City(cityName, cityX, cityY));
        }

    }


