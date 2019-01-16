#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
    	// Status number meaning:
    	// -2 ... Person has been vaccinated and cannot be infected
    	// -1 ... Person has recovered from the disease and cannot be infected
    	//  0 ... Person is healthy
    	// >0 ... Number of days till person recovers from the disease
        int status;
    public:
    	// Constructs one healthy person
        Person();
        // returns the string form of the person's status
		std::string status_string(); 
		// Returns the status of the person
        int get_status(); 
        // Sets the status of the person
        void set_status(int n); 
        // Updates the status of the person
        // if status > 1, status--
        // if status = 1, status = -1
        // if status = -1, -2, or 0, return
        void update(); 
        // infects the person for n days
        void infect(int n);
        // Inoculates the person (sets status to -2)
        void innoculate(); 
        // Returns true if the person is healthy 
        bool is_stable(); 
};
#endif
