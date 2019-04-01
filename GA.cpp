//
// Created by Ivan on 2019-03-21.
//

#include <iostream>
#include "GA.hpp"

GA::GA() :
        tourGenerator(TourGenerator()),
        population(Population(tourGenerator)),
        baseDistance(0),
        baseRoute(population.getTour(0)){

}

void GA::run() {

    count = 0;
    //move elite to the front
    population.sort();

    double fitness = population.getTour(0).getFitness();
//    baseRoute = population.getTour(0);
    //update base distance
    baseDistance = population.getTour(0).getTourDistance();
    int iteration = 0;
    double current_distance = baseDistance;
    double prev_distance = current_distance;
    improvement = (baseDistance - current_distance) / baseDistance;
    while (improvement < IMPROVEMENT_RATE && iteration < ITERATIONS) {
        //cross
        std::cout << iteration << " -> " << fitness << " , distance:" << population.getTour(0).getTourDistance();

        if(prev_distance > current_distance){
            std::cout << ", improved";
        }
        std::cout << std::endl;
        prev_distance = current_distance;
        population.crosses();

        for (int i = 1; i < POPULATION_SIZE; i++) {
            //mutation of tours
            population.getTour(i).mutate();
        }
        //move elite to the front
        population.sort();

        //get fitness value
        fitness = population.getTour(0).getFitness();
        current_distance = population.getTour(0).getTourDistance();
        improvement = (baseDistance - current_distance) / baseDistance;
        iteration++;
    }
    count = iteration;
}

void GA::report()  {

    std::cout << "Number of iterations: " << count << "\n";
    if (improvement >= IMPROVEMENT_RATE) {
        std::cout << "improvement achieved!" << std::endl;
    }else{
        std::cout << "improvement not achieved!" << std::endl;
    }
    std::cout << "Base distance: " << baseDistance << "\n";
    std::cout << "Base Route: " << "\n";
    std::cout << baseRoute << "\n";


    Tour solution = population.getTour(0);
    std::cout << "Final distance: " << solution.getTourDistance() << "\n";
    std::cout << "Solution Tour: " << "\n";
    std::cout << solution << "\n";


}
