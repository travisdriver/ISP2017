#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "Population.h"
#include "Person.h"

//*********************************
//  Name: Travis Driiver
//  EID: tpd399
//	Last dated edited: 12/10/17
//*********************************

using namespace std;

int main() {
	// Prompt user to input population size
	int popn;
	cout << "Enter population size: ";
	cin >> popn;
	
	// Set random seed based on clock time
    srand(time(NULL));
    // Crete variables
    float inocrate;
    float infrate;
    int inocn;
    // prepare files for writing data
    ofstream myfile;
    ofstream myfile2;
    myfile.open("data.csv");
    myfile2.open("data2.csv");
	
	// Iterate through inoculation rates
    for (int k = 0; k < 100; k ++) {
    	cout << "Inoculation:  " << k << " %" << endl;
    	// Iterate through infection rates
    	for (float i = 0; i < 100; i ++) {
    		cout << "Infection: " << i << " %" <<endl;
    		double avg_days = 0;
    		double avg_susc = 0;
    		// Run ten simulations each
    		for (int j = 0; j < 10; j++) {
                
                inocrate = k / 100.;
                infrate = i / 100.;
                // calculate number inoculated
                inocn = popn * inocrate;
				Population mypop = Population(popn);
    			mypop.innoculate(inocn);
    			// count number of people originally susceptible
    			int original_susc = mypop.count_susceptible();
    			mypop.case_zero();
    			mypop.set_probability_of_transfer(infrate);

    			int count = 0;
    			// Run until no one is infected
    			while (mypop.count_infected() > 0) {
    			    mypop.update();
    			    count++;
    			}
    			// add number of days survived to average
    			avg_days += count;
    			// add percentage of susceptible people still uninfected
    			avg_susc += mypop.count_susceptible()/double(original_susc);
    		}
    		// Calculate average of 10 simulations
    		avg_days = avg_days/10;
    		avg_susc = avg_susc/10;
    		// Write data to file
    		myfile << avg_days << ',';
    		myfile2 << avg_susc << ',';
    	}
    	// start new line in .csv file
    	myfile << '\n';
    	myfile2 << '\n';
    }
    // close files
    myfile.close();
    myfile2.close();
    return 0;
}
