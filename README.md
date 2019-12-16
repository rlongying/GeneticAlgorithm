# GeneticAlgorithm
> Genetic algorithm solves smooth or nonsmooth optimization problems with any types of constraints, including integer constraints. It is a stochastic, population-based algorithm that searches randomly by mutation and crossover among population members.
### How the Genetic Algorithm Works

1. The algorithm begins by creating a random initial population.
2. The algorithm then creates a sequence of new populations. At each step, the algorithm uses the individuals in the current generation to create the next population. To create the new population, the algorithm performs the following steps:
  - Scores each member of the current population by computing its fitness value. These values are called the raw fitness scores.
  - Scales the raw fitness scores to convert them into a more usable range of values. These scaled values are called expectation values.
  - Selects members, called parents, based on their expectation.
  - Some of the individuals in the current population that have lower fitness are chosen as elite. These elite individuals are passed to the next population.
  - Produces children from the parents. Children are produced either by making random changes to a single parent—mutation—or by combining the vector entries of a pair of parents—crossover.
  - Replaces the current population with the children to form the next generation.
3. The algorithm stops when one of the stopping criteria is met. See Stopping Conditions for the Algorithm.

*Above documentation is cited from [MathWorks](https://www.mathworks.com/help/gads/genetic-algorithm.html?s_tid=CRUX_lftnav)*
