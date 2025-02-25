//Noah Im ID:923109389
#include "Airplane.h"
#include "Airline.h"
#include <iostream>
using namespace std;

Airplane::Airplane(int n) : maxContainers(n), numContainers(0) {}

int Airplane::maxLoad(void) const{
    return maxContainers;
}
int Airplane::currentLoad(void) const{
    return numContainers;
}
bool Airplane::addContainers(int n){
    if (numContainers + n > maxContainers){
        return false;
    }
    else{
        numContainers += n;
        return true;
    }
}