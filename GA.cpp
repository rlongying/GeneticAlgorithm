//
// Created by Ivan on 2019-03-21.
//

#include <iostream>
#include "GA.hpp"

GA::GA(std::string filename) :
        tourGenerator(TourGenerator(filename)),
        population(Population(tourGenerator)),
        baseDistance(0) {

}

void GA::run() {

    //move elite to the front
    population.sort();

    double fitness = population.getTour(0).getFitness();

    //update base distance
    baseDistance = population.getTour(0).getTourDistance();
    int iteration = 0;
    while (iteration < ITERATIONS) {
        //cross
        std::cout << iteration << " -> " << fitness << " , distance:" << population.getTour(0).getTourDistance()
                  << std::endl;
        population.crosses();

        for (int i = 1; i < POPULATION_SIZE; i++) {
            //mutation of tours
            population.getTour(i).mutate();
        }
        //move elite to the front
        population.sort();

        //get fitness value
        fitness = population.getTour(0).getFitness();
        iteration++;
    }
}

void GA::report()  {
    std::cout << "Base distance: " << baseDistance << "\n";

    Tour solution = population.getTour(0);
    std::cout << "Final distance: " << solution.getTourDistance() << "\n";
    std::cout << "Solution Tour: " << "\n";
    std::cout << solution << "\n";


}
