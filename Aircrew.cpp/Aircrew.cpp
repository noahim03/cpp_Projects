#include <iostream>
#include <string>
#include "Aircrew.h"
using namespace std;

Aircrew::Aircrew(string name_str) : nm(name_str), flightsTaken(0), hoursWorked(0) {}//Constructor for the Aircrew class.

const double Aircrew::maxHours(void) const{//A member function returning the maximum number of hours a crew member can work per week.
    return 60.0;
}

const string Aircrew::name(void) const {//A member function returning the name of the aircrew.
    return nm;
}

void Aircrew::setFlights(int i){//A member function used to set the number of flights worked.
  flightsTaken = i;
}

void Aircrew::setHours(double h){//A member function used to set the current number of hours worked.
  hoursWorked = h;
}

void Aircrew::print(void) const{//A member function used to print the name of the aircrew, the number of flights worked, and the number of hours worked.
  cout << type() << ": " << nm << " has operated " << flightsTaken << " flights for a total of " << hoursWorked << " hours this week" << endl;
  cout << "Available flights: " << maxFlights() - flightsTaken << endl;
  cout << "Available hours: " << maxHours() - hoursWorked << endl;
}

void Aircrew::scheduleFlight(int i, double h)const{//A member function used to determine if a crew member can be scheduled for a given number of flights and hours.
  cout<<"Attempting to schedule for " << i << " stop(s) " << h << " hours flight..."<< endl;
  int new_flights = flightsTaken + i;
  double new_hours = hoursWorked + h;

  if(new_flights <= maxFlights() && new_hours <= maxHours()){
    cout << "This crew member can be scheduled" << endl;
    cout << "Done scheduling "<< nm << endl;
  }
  else if (new_flights > maxFlights()){
    cout << "This crew member should be replaced" << endl;
  }
}

Aircrew* Aircrew::makeAircrew(char ch, string name_str){//A static member function used to create a new aircrew object based on the type of aircrew.
  if(ch == 'P'){
    return new Pilot(name_str);
  }
  else if(ch == 'A'){
    return new Attendant(name_str);
  }
  else if(ch == 'T'){
    return new TaggedAttendant(name_str);
  }
  else{
    return nullptr;
  }
}

Aircrew::~Aircrew(void){}//Destructor for the Aircrew class.

Pilot::Pilot(string name_str) : Aircrew(name_str){}//Constructor for the Pilot class.
const string Pilot::type(void) const {
  return "Pilot";
}
const int Pilot::maxFlights(void) const{
  return 5;
}

Attendant::Attendant(string name_str) : Aircrew(name_str){}//Constructor for the Attendant class.
const string Attendant::type(void) const {
  return "Attendant";
}
const int Attendant::maxFlights(void) const{
  return 8;
}
TaggedAttendant::TaggedAttendant(string name_str) : Aircrew(name_str){}//Constructor for the TaggedAttendant class.
const string TaggedAttendant::type(void) const {
  return "Tagged Attendant";
}
const int TaggedAttendant::maxFlights(void) const{
  return 8;
}
void TaggedAttendant::scheduleFlight(int f, double h) const{
  cout<<"Attempting to schedule for " << f << " stop(s) " << h << " hours flight..."<< endl;
  int new_flights = flightsTaken + f;
  double new_hours = hoursWorked + h;

  if(new_flights <= maxFlights() && new_hours <= maxHours()){
    cout << "This crew member can be scheduled" << endl;
    cout << "Done scheduling "<< nm << endl;
  }
  else if (new_flights > maxFlights()){
    cout << "This crew member should be replaced" << endl;
  }
}