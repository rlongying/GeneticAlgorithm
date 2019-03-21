//
// Created by Ivan on 2019-03-19.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP


#include <vector>
#include "City.hpp"

class Tour {

private:
    int  SCALE_FACTOR = 1000000;
    double  MUTATE_RATE = 0.15;
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
     * calculate the fitness
     */
    void updateFitnes();

    /**
     * update the fitness, and get the fitness of this tour
     * @return fitness
     */
    double getFitness() {
        //update only once right before trying to get the fitness
        updateFitnes();
        return fitness;
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

    friend std::ostream &operator<<(std::ostream &os, const Tour &tour);

};


#endif //GENETICALGORITHM_TOUR_HPP
