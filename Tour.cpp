//
// Created by Ivan on 2019-03-19.
//





#include <iostream>
#include "Tour.hpp"

void Tour::mutate() {

}

std::ostream &operator<<(std::ostream &os, const Tour &tour) {

//    os << &tour.cityList << " : ";
    for (int i = 0; i < tour.cityList.size(); i++) {
         os << *tour.cityList[i] << "  ";
    }
    return os;
}

void Tour::setCity(int index, City *city) {
    cityList[index] = city;
}

void Tour::updateFitnes() {
    double totalDistance = 0;
    auto it = cityList.begin();
    for(it ++ ; it != cityList.end(); it++){
        totalDistance += (*it)->distance(*(it -1));
    }

    //initial fitness
    fitness = SCALE_FACTOR / totalDistance;
}

void Tour::swap(Tour &lhs, Tour &rhs) {



}

