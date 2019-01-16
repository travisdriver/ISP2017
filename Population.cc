#include "Population.h"

using namespace std;

Population::Population() {
	popsize = 0;
	infrate = 0;
}
Population::Population(int npeople) {
	infrate = 0;
    popsize = npeople;
    for (int i = 0; i < npeople; i++) {
        popvec.push_back(Person::Person());
    }
}
void Population::set_probability_of_transfer(float probability) {
	infrate = probability;
}
void Population::random_infection() {
    int n = rand() % popsize;
    if (popvec[n].get_status() == 0) {
        popvec[n].infect(6);
    }
}
void Population::infect_neighbors() {
	for (int i = 0; i < popsize; i++) {
		if (popvec[i].get_status() > 0) {
			float bad_luck = (float) rand()/(float)RAND_MAX;
			if (i-1 >= 0 && popvec[i-1].get_status() == 0 && bad_luck < infrate) { 
				popvec[i-1].infect(6); 
			}
			if (i+1 < popsize && popvec[i+1].get_status() == 0 && bad_luck < infrate) { 
					popvec[i+1].infect(6); 
					i++;
			}
		}
	}
}
void Population::random_infection(int npeople) {
	for (int i = 0; i < npeople; i++) {
		float bad_luck = (float) rand()/(float)RAND_MAX;
		if (bad_luck < infrate) {
			random_infection();
		}
	}
}
void Population::case_zero() {
	int count = 0;
	while ( count < 1 ) {
		int n = rand() % popsize;
		if (popvec[n].get_status() != -2) {
			popvec[n].infect(6);
			count++;
		}
	}
}
void Population::innoculate(int npeople) {
	int count = 0;
	while ( count < npeople ) {
		int n = rand() % popsize;
		if (popvec[n].get_status() != -2) {
			popvec[n].innoculate();
			count++;
		}
	}
}
void Population::print_pop() {
    for (int i = 0; i < popsize; i++) {
        if ( popvec[i].get_status() == 0 ) { cout << "? "; }
        else if ( popvec[i].get_status() > 0 ) { cout << "+ "; }
        else if ( popvec[i].get_status() == -1 ) { cout << "- "; }
        else { cout << ". "; }
    }
	cout << endl;
}
void Population::update_basic() {
	for (int i = 0; i < popsize; i++) {
        popvec[i].update();
    }

}
void Population::update() {
    for (int i = 0; i < popsize; i++) {
    	if (popvec[i].get_status() > 0) {
    		random_infection(6);
    	}
        popvec[i].update();
    }
}
int Population::count_infected() {
    int infected = 0;
    for (int i = 0; i < popsize; i++) {
        if (popvec[i].get_status() > 0) { infected++; }
    }
    return infected;
}
int Population::count_susceptible() {
    int susceptible = 0;
    for (int i = 0; i < popsize; i++) {
        if (popvec[i].get_status() == 0) { susceptible++; }
    }
    return susceptible;
}
