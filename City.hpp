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

    /**
     * calculate the distance between two cities
     * @param other another city to compare
     * @return the distance in a absolute value
     */
    double distance(City *other) const;

    std::string getName() const {return name;}

    friend std::ostream& operator<<(std::ostream & os, const City & city);
};


#endif //GENETICALGORITHM_CITY_HPP
