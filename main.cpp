#include "GA.hpp"

using namespace std;
int main() {

    GA ga("../cities.txt");
    ga.run();
    ga.report();

//    TourGenerator tourGenerator("../cities.txt");
//
//    Population population(tourGenerator);
//
//    //move elite to front
//    population.sort();
//
//    double fitness = population.getTour(0).getFitness();
//
//    int iteration = 0;
//    while (iteration < ITERATIONS) {
//        //cross
//        cout << iteration << " -> " << fitness << " , distance:" << population.getTour(0).getTourDistance() << endl;
//        population.crosses();
//
//        for(int i = 1; i < POPULATION_SIZE; i++){
//            //mutation of tours
//            population.getTour(i).mutate();
//        }
//        //move elite to the front
//        population.sort();
//
//        //get fitness value
//        fitness = population.getTour(0).getFitness();
//        iteration ++;
//    }

//    for (int i = 0; i < POPULATION_SIZE; i++) {
//        cout << "+++++++++++" << i << "+++++++++" << endl;
//
//        cout << population.getTour(i).getFitness() << " -> " << population.getTour(i) <<endl;
//    }
//
//    population.sort();
//
//    cout << "after sort" << endl;
//
//    for (int i = 0; i < POPULATION_SIZE; i++) {
//        cout << "+++++++++++" << i << "+++++++++" << endl;
//
//        cout << population.getTour(i).getFitness() << " -> " << population.getTour(i) <<endl;
//    }



}