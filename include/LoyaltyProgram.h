
#ifndef LOYALTYPROGRAM_H
#define LOYALTYPROGRAM_H

#include <string>
#include <iostream>
using namespace std;


#include <string>
#include "Passenger.h"
class Passenger;
class LoyaltyProgram {
public:
    void calculateLoyaltyLevel(int miles);
    void showLoyaltyStatus(Passenger& p);
    bool eligible(int miles);
    double applyDiscount(double amount);

    string getLoyaltyLevel() const;
    double getDiscountRate() const;

private:
    string loyaltyLevel;
    double discountRate = 0.0;

};
#endif

