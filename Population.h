#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <iostream>
#include "Person.h"

class Population {
    private:
    	// Vector containing people in population
		std::vector <Person::Person> popvec;
		// Population size
        int popsize;
        // Infection rate, 0 <= infrate <=1
        float infrate;
    public:
    	// Default constructor
    	Population();
    	// Constructs population the a specified number of people
        Population(int npeople);
        // Sets the infection rate of the disease in the population
        void set_probability_of_transfer(float probability);
        // Infects a person in the population randomly
        void random_infection();        
        void infect_neighbors();
        // Infects a specified number of people randomly
        void random_infection(int npeople);
        // Creates first instance of the disease within the population
        void case_zero();
        // Inoculate a specified number of people
        void innoculate(int npeople);
        // Prints a visual representation of the population
        // '?' = person is suspecible
        // '+' = person is infected
        // '-' = person is recovered
        // '.' = person is inoculated
        void print_pop();
        // Runs Person::update() on every person in population
        void update_basic();
        // Runs Person::update() on every person in population
        // and infects others based on number of infected persons
        void update();
        // Returns the number of infected people in the population
        int count_infected();
        // Returns the number of susceptible people in the population
        int count_susceptible();
};
#endif
