//
// Created by Ivan on 2019-03-20.
//

#include "Population.hpp"
#include <algorithm>
#include <iostream>

Population::Population(TourGenerator &generator) : generator(generator) {

    for (int i = 0; i < POPULATION_SIZE; i++) {
        Tour tour = generator.generateRandomTour();
        population.push_back(tour);

    }
}

//
void Population::sort() {
    std::sort(population.begin(),
              population.end(),
              [](Tour &t1, Tour &t2) { return t1.getFitness() > t2.getFitness(); });
}

Tour Population::crossover(Tour tour1, const Tour &tour2) {

    //keep cities from seq1 to seq2 (inclusive) in tour1 not change
    int seq1 = CITIES_IN_TOUR / 3;
    int seq2 = CITIES_IN_TOUR / 3 * 2;

    //the current pos of city in tour2
    int posTour2 = 0;

    //fill in 0 to seq1-1 in tour1 with cities from tour 2
    //ignore cites already exist in tour1
    int curPosTour1 = 0;
    while (curPosTour1 < seq1) {

        City *city = tour2.getCity(posTour2);
        if (!tour1.hasCity(seq1, seq2, city)) {

            tour1.setCity(curPosTour1, city);
            curPosTour1++;
        }
        posTour2++;
    }

    //fill in seq2 + 1 to the end with cities from tour2
    curPosTour1 = seq2 + 1;
    while (curPosTour1 < CITIES_IN_TOUR) {

        City *city = tour2.getCity(posTour2);
        if (!tour1.hasCity(seq1, seq2, city)) {

            tour1.setCity(curPosTour1, city);
            curPosTour1++;
        }
        posTour2++;
    }

    return tour1;
}


void Population::crosses() {

    std::vector<Tour> offsrpings;
//
//    //sort first
//    sort();

    //move elite to the first
    offsrpings.push_back(getTour(0));

    for (int i = 1; i < POPULATION_SIZE; i++) {
        Tour parent1 = selectParent();
        Tour parent2 = selectParent();

        offsrpings.push_back(crossover(parent1, parent2));
    }

   population = offsrpings;
}

Tour Population::selectParent() {

    myclock::duration d = myclock::now() - BEGINING_TIME;
    std::default_random_engine engine(d.count());
    std::uniform_int_distribution<int> indexGenerator(1, CITIES_IN_TOUR);

    //get parent pool
    int parents[PARENT_POOL_SIZE] = {};

    for (int i = 0; i < PARENT_POOL_SIZE; i++) {
        parents[i] = indexGenerator(engine);

        for (int j = 0; j < i; j++) {
            if(parents[j] == parents[i]){
                i --;
                break;
            }
        }
    }

    int fittest = 0;

    for (int i = 1; i < PARENT_POOL_SIZE; i++) {
        if(getTour(i).getFitness() > getTour(fittest).getFitness()){
            fittest = i;
        }
    }

    return getTour(fittest);
}

