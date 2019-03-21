//
// Created by Ivan on 2019-03-20.
//

#include "Population.hpp"
#include <algorithm>

Population::Population(int size, TourGenerator &generator) : populationSize(size), generator(generator) {

    for (int i = 0; i < size; i++) {
        Tour tour = generator.generateRandomTour();
        population.push_back(tour);

    }
}

//
void Population::sort() {
    std::sort(population.begin(),
              population.end(),
              [](Tour &t1, Tour &t2) { return t1.getFitness() < t2.getFitness(); });
}

void Population::crossover(Tour &tour1, Tour &tour2) {

}

void Population::crosses() {

}

