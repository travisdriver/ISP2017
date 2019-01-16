#include "Person.h"

Person::Person() {
    status = 0;
}
std::string Person::status_string() {
    if (status == 0) { return "susceptible"; }
    else if (status == -1) { return "recovered"; }
    else if (status == -2) { return "innoculated"; }
    else { return "sick (" + std::to_string(status) + " to go)"; }
}
int Person::get_status() {
    return status;
}
void Person::set_status(int n) {
    status = n;
}
void Person::update() {
    if (status == 0 || status == -1 || status == -2) { return; }
    else if (status > 1) { status--;}
    else if (status == 1) { status = -1; }
}
void Person::infect(int n) {
    status = n;
}
void Person::innoculate() {
    status = -2;
}
bool Person::is_stable() {
    if (status < 0) { return true; }
    else { return false; }
}
