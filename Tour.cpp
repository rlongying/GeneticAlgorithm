//
// Created by Ivan on 2019-03-19.
//


#include <iostream>
#include <random>
#include "Tour.hpp"

void Tour::mutate() {

    myclock::duration d = myclock::now() - beginning;
    std::default_random_engine engine(d.count());
    std::uniform_real_distribution<double> perGenerator(0.0, 1.0);

    for (int i = 1; i < cityList.size(); i++) {
        double percentage = perGenerator(engine);
        if (percentage <= MUTATE_RATE) {
            swapCity(i, i - 1);
        }
    }

}

std::ostream &operator<<(std::ostream &os, const Tour &tour) {

//    os << &tour.cityList << " : ";
    for (int i = 0; i < tour.cityList.size(); i++) {
        os << i << "-" << *tour.cityList[i] << "  ";
    }
    return os;
}

void Tour::setCity(int index, City *city) {
    cityList[index] = city;
}

void Tour::swapCity(int first, int second) {
    City *temp = cityList[first];

    cityList[first] = cityList[second];
    cityList[second] = temp;
}

bool Tour::hasCity(int start, int end, City *city) const {
    bool hasFound = false;

    for (int i = start; i <= end; i++) {
        if (cityList[i]->getName() == city->getName()) {
            hasFound = true;
            break;
        }
    }

    return hasFound;
}

double Tour::getTourDistance() const {
    double totalDistance = 0;
    auto it = cityList.begin();
    for (it++; it != cityList.end(); it++) {
        totalDistance += (*it)->distance(*(it - 1));
    }
    return totalDistance;
}

//void Tour::swap(Tour &lhs, Tour &rhs) {
//
//
//
//}

