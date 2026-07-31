#include "LoyaltyProgram.h"
#include <iostream>
#include"Passenger.h"

using namespace std;

void LoyaltyProgram::calculateLoyaltyLevel(int miles) {
    if (miles >= 50000) {
        loyaltyLevel = "Gold";
        discountRate = 0.30;
    }
    else if (miles >= 25000) {
        loyaltyLevel = "Silver";
        discountRate = 0.20;
    }
    else if (miles >= 10000) {
        loyaltyLevel = "Bronze";
        discountRate = 0.10;
    }
    else {
        loyaltyLevel = "Basic";
        discountRate = 0.0;
    }
}

void LoyaltyProgram::showLoyaltyStatus(Passenger& p) {
    calculateLoyaltyLevel(p.getMiles());
    cout <<":::::::::::::::::::::::::::::::::::::\n";
    cout << "Hi " << p.name << ", you are a " << loyaltyLevel << " member.\n";
    cout << "You have " << p.getMiles() << " miles and get " << discountRate * 100 << "% off on flights.\n";
    cout <<":::::::::::::::::::::::::::::::::::::\n";
}
std::string LoyaltyProgram::getLoyaltyLevel() const {
    return loyaltyLevel;
}

double LoyaltyProgram::getDiscountRate() const {
    return discountRate;
}

bool LoyaltyProgram::eligible(int miles) {
    calculateLoyaltyLevel(miles);
    return miles >= 10000;
}

double LoyaltyProgram::applyDiscount(double amount) {
    return amount * (1 - discountRate);
}

