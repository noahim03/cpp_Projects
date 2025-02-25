//Noah Im ID:923109389
#include "Airline.h"
#include "Airplane.h"
#include <iostream>
using namespace std;

Airline::Airline(int nA321, int nB777, int nB787) : nAirplanes(nA321 + nB777 + nB787) {
    airplaneList = new Airplane*[nAirplanes];
    int num = 0;
    for (int i = 0; i < nA321; i++) {
        airplaneList[num] = new Airplane(10);
        ++num;
    }
    for (int i = nA321; i < nA321 + nB777; i++) {
        airplaneList[num] = new Airplane(32);
        ++num;
    }
    for (int i = nA321 + nB777; i < nA321 + nB777 + nB787; i++) {
        airplaneList[num] = new Airplane(40);
        ++num;
    }
    static bool printedAirplaneList = false; 
    if (!printedAirplaneList) { 
        for (int i = 0; i < nAirplanes; i++) {
            cout << "Airplane " << (i + 1) << " maximum load " << airplaneList[i]->maxLoad() << endl;
        }
        printedAirplaneList = true; 
    }
}

Airline::~Airline() {
    for (int i = 0; i < nAirplanes; i++) {
        delete airplaneList[i];
        cout << "deallocating airplane " << (i + 1) << endl;
    }
    delete[] airplaneList;
}

void Airline::addShipment(int size) {
    if(size < 0) {
        throw invalid_argument("must be positive");
        return;
    }
    for (int i = 0; i < nAirplanes; i++) {
        if(airplaneList[i]->addContainers(size)) {
            cout << size << " containers added to airplane " << (i + 1) << endl;
            return;
        }
    }
    cout << " could not fit " << size << " containers" << endl;
}

void Airline::printSummary() const {
    cout << "Summary:" << endl;
    for (int i = 0; i < nAirplanes; i++) {
        if (airplaneList[i]->currentLoad() > 0) {
            cout << "airplane " << (i + 1) << " " << airplaneList[i]->currentLoad() << "/" << airplaneList[i]->maxLoad() << endl;
        }
    }
}