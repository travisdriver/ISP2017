#include "Person.h"
#include "Population.h"

using namespace std;

int main() {
	// create person
	Person joe;
	// set random seed
	srand(time(NULL));
	int step = 1;

	// run until joe has recovered from the disease
	while (!joe.is_stable()) {
    joe.update();
    float bad_luck = (float) rand()/(float)RAND_MAX;
    // infect for 5 days if random float is less than .95 and joe is sesceptible
    if (bad_luck<.95 && joe.get_status() == 0)
      joe.infect(5);
    cout << "On day " << step << ", Joe is "
         << joe.status_string() << endl;
    step++;
    }
    return 0;
}
