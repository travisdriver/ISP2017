#include "Person.h"
#include "Population.h"

using namespace std;

int main() {
	// create population of size 20
	Population mypop = Population(20);
	int step = 0;
	srand(time(NULL));
	// infect random person
	mypop.random_infection();
	// run until there are no infected individuals
	while (mypop.count_infected() > 0) {
	  step++;
      cout << "In step: " << step << " #sick: "<< mypop.count_infected() << ": ";
      mypop.update();
      mypop.print_pop();
    }
    cout << "Disease ran its course by step " << step << endl;
    return 0;
}
