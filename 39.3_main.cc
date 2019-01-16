#include "Person.h"
#include "Population.h"

using namespace std;

int main() {
	// create population of size 20
	Population mypop = Population(20);
	float infrate;
	// prompt user to input infect rate between 0 and 1
	cout << "Enter infection rate (between 0 and 1): ";
	cin >> infrate;
	// error handling
	if (infrate < 0 || infrate > 1) {
		cout << "Invalid input parameters" << endl;
		return 0;
	}

	// set population infection rate attribute
	mypop.set_probability_of_transfer(infrate);

	srand(time(NULL));
	mypop.random_infection();
	int step = 0;
	// run until no person is infected
	while (mypop.count_infected() > 0) {
	  step++;
      cout << "In step: " << step << " #sick: "<< mypop.count_infected() << ": ";
      mypop.print_pop();
      // attempt to infect the neighbors of the infected individuals 
      mypop.infect_neighbors();
      // update status of each person
      mypop.update_basic();
    }
    cout << "Disease ran its course by step " << step << endl;
    return 0;
}
