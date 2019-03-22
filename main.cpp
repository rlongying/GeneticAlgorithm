#include <iostream>
#include "Tour.hpp"
#include "TourGenerator.hpp"
#include "Population.hpp"

using namespace std;
int main() {

    TourGenerator tourGenerator("../cities.txt");

    Population population(tourGenerator);



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

}