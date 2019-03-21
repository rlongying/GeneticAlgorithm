#include <iostream>
#include "Tour.hpp"
#include "TourGenerator.hpp"
#include "Population.hpp"

using namespace std;
int main() {
    const int POPULATION_SIZE = 32;
//
    TourGenerator tourGenerator("../cities.txt");
//
    Population population(POPULATION_SIZE, tourGenerator);

    for (int i = 0; i < POPULATION_SIZE; i++) {
        cout << "+++++++++++" << i << "+++++++++" << endl;

        cout << population.getTour(i).getFitness() << " -> " << population.getTour(i) <<endl;
    }

    population.sort();

    cout << "after sort" << endl;

    for (int i = 0; i < POPULATION_SIZE; i++) {
        cout << "+++++++++++" << i << "+++++++++" << endl;

        cout << population.getTour(i).getFitness() << " -> " << population.getTour(i) <<endl;
    }


//    vector<Tour> tours;
//
//    for (int i = 0; i < POPULATION_SIZE; i++) {
//        Tour tour = tourGenerator.generateRandomTour();
//        tours.push_back(tour);
//
//    }
//
//    for (int i = 0; i < POPULATION_SIZE; i++) {
//        cout << "+++++++++++" << i << "+++++++++" << endl;
//
//        cout << tours[i].getFitness() << " -> " << tours.at(i) <<endl;
//    }

//    tours[POPULATION_SIZE - 1].setCity(1, new City("A", 1, 2));
//
//    cout << tours[POPULATION_SIZE - 1].getFitness() << " -> " << tours.at(POPULATION_SIZE - 1) <<endl;


}