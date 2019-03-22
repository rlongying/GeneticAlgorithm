//
// Created by Ivan on 2019-03-19.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP


#include <vector>
#include <chrono>
#include "City.hpp"
#include "Constants.hpp"

class Tour {


private:
    std::vector<City *> cityList;
    double fitness;

public:
    Tour(std::vector<City *> list) : cityList(list), fitness(0) {}

//    Tour(const Tour &tour) :
//            SCALE_FACTOR(tour.SCALE_FACTOR),
//            MUTATE_RATE(tour.MUTATE_RATE),
//            cityList(tour.cityList),
//            fitness(tour.fitness) {}

//    Tour &operator=(const Tour &tour) {
//
//    }

//    void swap(Tour& lhs, Tour& rhs);

    /**
     * get the fitness of this tour
     * @return fitness
     */
    double getFitness() {
        return SCALE_FACTOR / getTourDistance();;
    }

    /**
     * change a city inside the tour, and update fitness
     * @param index the target position to change
     * @param city  the new value
     */
    void setCity(int index, City *city);

    /**
     * perform mutation of the positions inside the tour, and update the fitness
     */
    void mutate();

    /**
     * test if city exist in the tour from start to end
     * @param start start index, included
     * @param end  end index, included
     * @param city  target city to find
     * @return  true, if found. otherwise, false
     */
    bool hasCity(int start, int end, City *city) const;

    City *getCity(int pos) const {
        return cityList[pos];
    }

    double getTourDistance() const;

    void swapCity(int first, int second);

    friend std::ostream &operator<<(std::ostream &os, const Tour &tour);

};


#endif //GENETICALGORITHM_TOUR_HPP
