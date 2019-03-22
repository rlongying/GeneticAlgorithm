//
// Created by Ivan on 2019-03-20.
//

#include "Population.hpp"
#include <algorithm>
#include <iostream>

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

Tour Population::crossover(Tour tour1, const Tour &tour2) {

    //keep cities from seq1 to seq2 (inclusive) in tour1 not change
    int seq1 = tour1.size() / 3;
    int seq2 = tour1.size() / 3 * 2;

    std::cout << "from " << seq1 << " to " << seq2 << std::endl;
    //the current pos of city in tour2
    int posTour2 = 0;

    //fill in 0 to seq1-1 in tour1 with cities from tour 2
    //ignore cites already exist in tour1
    int curPosTour1 = 0;
    while (curPosTour1 < seq1) {

        City * city = tour2.getCity(posTour2);
        if(!tour1.hasCity(seq1, seq2, city)){

            tour1.setCity(curPosTour1, city);
            curPosTour1 ++;
        }
        posTour2++;
    }

    //fill in seq2 + 1 to the end with cities from tour2
    curPosTour1 = seq2 + 1;
    while (curPosTour1 < tour1.size()) {

        City * city = tour2.getCity(posTour2);
        if(!tour1.hasCity(seq1, seq2, city)){

            tour1.setCity(curPosTour1, city);
            curPosTour1 ++;
        }
        posTour2++;
    }

    return tour1;
}

void Population::crosses() {


}

