#include "Booking.h"
#include "Passenger.h"
#include "Payment.h"
#include "Seat.h"
#include "Tickets.h"
#include "Flight.h"
#include "MealSelection.h"
#include "LoyaltyProgram.h"
#include "CarryLuggage.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


Booking::Booking() {
    for (int i = 0; i < 20; i++) {
        seats[i] = '0';
    }

    ifstream seatfile("seats.txt");
    if (seatfile.is_open()) {
        for (int i = 0; i < 20; i++) {
            seatfile >> seats[i];
        }
        seatfile.close();
    }
}


void Booking::startBooking(Passenger& p, Payment& pay, Seat& s, Tickets& t,
                           MealSelection& m, LoyaltyProgram& l, CarryLuggage& c) //association
                           {
    Flight f;
    f.displayFlights();

    string selectedFlightID;
    cout << "Enter Flight ID you want to book: ";
    cin >> selectedFlightID;

    if (!f.isValidFlightID(selectedFlightID)) {
        cout << "Invalid Flight ID. Booking cancelled.\n";
        return;
    }

    ifstream flightFile("flights.txt");
    string flightID, depCity, destCity, depTime, miles;
    bool flightFound = false;

    while (flightFile >> flightID >> depCity >> destCity >> depTime >> miles) {
        if (flightID == selectedFlightID) {
            flightFound = true;
            break;
        }
    }
    flightFile.close();

    if (!flightFound) {
        cout << "Error retrieving flight details. Booking cancelled.\n";
        return;
    }

   
    cout << "--- Seat Selection ---\n";
    int index;
    while (true) {
        cout << "Enter seat index (0-19): ";
        cin >> index;

        if (index < 0 || index >= 20) {
            cout << "Invalid seat index. Please try again.\n";
            continue;
        }

        if (seats[index] == '1') {
            cout << "Seat already taken. Please choose another.\n";
            continue;
        }
        break;
    }


    cout << "Do you want window seat? (y/n): ";
    char choice;
    cin >> choice;
    bool window = (choice == 'y' || choice == 'Y');


    int price = s.seatPrice(window);
    pay.total += price;
    seats[index] = '1';
    p.setSeatNumber(index);


    ofstream outseat("seats.txt");
    for (int i = 0; i < 20; i++) {
        outseat << seats[i];
    }
    outseat.close();

 
    if (l.eligible(p.getMiles())) {
        double originalTotal = pay.total;
        pay.total = l.applyDiscount(pay.total);
        cout << "Applied " << l.getLoyaltyLevel() << " level discount ("
             << (l.getDiscountRate() * 100) << "%)\n";
        cout << "Price reduced from " << originalTotal << " to " << pay.total << endl;
    }

   
    int earnedMiles = pay.total / 50;
    p.addMiles(earnedMiles);
    cout << "Earned " << earnedMiles << " miles from this booking!\n";


    updatePassengerMiles(p);

  
    pay.receivePayment();

 
    t.generateTicket(&p, selectedFlightID, pay.total, depCity, destCity, depTime);
    t.displayTicket(&p);
}


void Booking::cancelBooking(Passenger& passenger) {
    cout << "--- Cancelling Booking ---\n";
    cout << "Ticket for Passenger Name: [" << passenger.name
         << "] Passport Number: [" << passenger.passport
         << "] has been cancelled\n";

    int seatNum = passenger.getSeatNumber();
    if (seatNum >= 0 && seatNum < 20) {
        seats[seatNum] = '0';

        ofstream seatfile("seats.txt");
        for (int i = 0; i < 20; i++) {
            seatfile << seats[i];
        }
        seatfile.close();
    }

    
    int penalty = 50;
    int currentMiles = passenger.getMiles();
    if (currentMiles >= penalty) {
        passenger.addMiles(-penalty);
        cout << penalty << " miles deducted due to cancellation.\n";
    } else {
        cout << "Not enough miles to deduct penalty.\n";
    }

    updatePassengerMiles(passenger);
}


void Booking::updatePassengerMiles(Passenger& p) {
    ifstream inFile("passenger.txt");
    ofstream outFile("temp.txt");
    string n, pass;
    int m;
    bool updated = false;

    while (inFile >> n >> pass >> m) {
        if (n == p.name && pass == p.passport) {
            outFile << n << " " << pass << " " << p.getMiles() << endl;
            updated = true;
        } else {
            outFile << n << " " << pass << " " << m << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("passenger.txt");
    rename("temp.txt", "passenger.txt");

    if (!updated) {
        cout << "Warning: Passenger record not found for update.\n";
    }
}
