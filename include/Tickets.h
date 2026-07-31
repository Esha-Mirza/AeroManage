#ifndef TICKETS_H
#define TICKETS_H

#include "Passenger.h"
#include <string>

class Tickets {
public:
    void generateTicket(Passenger* p, const std::string& flight, int cost,
                      const std::string& depCity, const std::string& destCity,
                      const std::string& time);
    void displayTicket(Passenger* p);
};

#endif