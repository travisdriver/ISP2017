#include "Person.h"
#include "Population.h"

using namespace std;

int main() {
	int popn;
	// prompt user to input population size
	cout << "Enter population size: ";
	cin >> popn;
	Population mypop = Population(20);

	float infrate;
	float inocrate;
	// prompt user to input infection rate between 0 and 1
	cout << "Enter infection rate (>=0 and <=1): ";
	cin >> infrate;
	// error handling
	if (infrate < 0 || infrate > 1) {
		cout << "Invalid input parameters" << endl;
		return 0;
	}

	// prompt user to input inoculation rate between 0 and less than 1
	cout << "Enter inoculation rate (>=0 and <1): ";
	cin >> inocrate;
	// error handling
	if (inocrate < 0 || inocrate >= 1) {
		cout << "Invalid input parameters" << endl;
		return 0;
	}

	// inoculate based on inoculation rate
	mypop.innoculate(popn*inocrate);
	
	mypop.set_probability_of_transfer(infrate);
	srand(time(NULL));
	// create 'case zero' of the disease in population
	mypop.case_zero();
	int step = 0;
	while (mypop.count_infected() > 0) {
	  step++;
      cout << "In step: " << step << " #sick: "<< mypop.count_infected() << ": ";
      mypop.print_pop();
      // infect neightbors
      mypop.infect_neighbors();
      // update status of each person
      mypop.update_basic();
    }
    cout << "Disease ran its course by step " << step << endl;
    return 0;
}
