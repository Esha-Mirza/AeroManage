
#ifndef PASSENGER_H
#define PASSENGER_H

#include "User.h"
#include <string>
#include <iostream>
using namespace std;

class Passenger : public User {
private:
    int seatNumber = -1;
    int miles = 0;
public:
    string name;
    string passport;
    void registerUser();
    void login();
    void viewBookings();
    string travelTime;
    string bookedMeal;
    void setSeatNumber(int seat) {
        seatNumber = seat; }
    int getSeatNumber() const {
        return seatNumber; }
    int getMiles() const {
        return miles; }
    void addMiles(int m) {
        miles += m; }

};


#endif
