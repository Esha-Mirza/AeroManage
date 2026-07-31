
#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
using namespace std;


class Flight {
public:
    void displayFlights();
    bool isValidFlightID(const std::string& flightID);
};



#endif