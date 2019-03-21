//
// Created by Ivan on 2019-03-19.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>

class City {

private:
    std::string name;
    int x;
    int y;

public:
    City(std::string name, int x, int y) : name(name), x(x), y(y){}

    double distance(City *other) const;

    friend std::ostream& operator<<(std::ostream & os, const City & city);
};


#endif //GENETICALGORITHM_CITY_HPP
