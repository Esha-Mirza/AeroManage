

#ifndef BOOKING_H
#define BOOKING_H


#include "Passenger.h"
#include "Payment.h"
#include "Seat.h"
#include "Tickets.h"
#include "MealSelection.h"
#include "LoyaltyProgram.h"
#include "CarryLuggage.h"

class Booking {
public:
    char seats[20];//composition of seats.cpp:its taking the array
    Booking();

    void updateSeatsFile();
    void updatePassengerMiles(Passenger& p);//association

    void startBooking(Passenger& p, Payment& pay, Seat& s, Tickets& t, MealSelection& m, LoyaltyProgram& l, CarryLuggage& c);

    void cancelBooking(Passenger& passenger);

};

#endif
