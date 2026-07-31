#include "Flight.h"
#include <iostream>
#include <fstream>
//#include <vector>

using namespace std;

void Flight::displayFlights() {
    ifstream fin("flights.txt");
    if (!fin.is_open()) {
        cout << "No flights available or unable to open flights file.\n";
        return;
    }

    string id, dep, dest, time;
    int miles;
    bool hasFlights = false;

    cout << "\nAvailable Flights:\n";
    cout << "//////////////////////////////////////////////////////////////\n";
    cout<<"Re-enter your FLight id! For confirmation \n";
    while (fin >> id >> dep >> dest >> time >> miles) {
        hasFlights = true;
        cout << "ID: " << id
             << ", From: " << dep
             << ", To: " << dest
             << ", Time: " << time
             << ", Miles: " << miles << "\n";
    }
    cout << "//////////////////////////////////////////////////////////////\n";
    
    if (!hasFlights) {
        cout << "No flights currently available.\n";
    }

    fin.close();
}

bool Flight::isValidFlightID(const string& flightID) {
    ifstream fin("flights.txt");
    if (!fin.is_open()) return false;

    string id, dep, dest, time;
    int miles;
    bool found = false;
    
    while (fin >> id >> dep >> dest >> time >> miles) {
        if (id == flightID) {
            found = true;
            break;
        }
    }
    fin.close();
    return found;
}
