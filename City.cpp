//
// Created by Ivan on 2019-03-19.
//

#include <iostream>
#include <cmath>
#include "City.hpp"

double City::distance(City *other) const {

    return sqrt(pow(x - other->x, 2) + pow(y - other->y, 2));
}

std::ostream &operator<<(std::ostream &os, const City &city) {
    os << "[" << city.name << ", " << city.x << ", " << city.y << "]";
    return os;
}
