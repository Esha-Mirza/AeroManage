#include "Tickets.h"
#include "Passenger.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Tickets::generateTicket(Passenger* p, const string& flight, int cost,
                           const string& depCity, const string& destCity,
                           const string& time) {

    string filename = "ticket_" + p->passport + ".txt";
    ofstream pt(filename);

    pt << "----------------------------------------\n";
    pt << "          YOUR BOARDING PASS\n";
    pt << "----------------------------------------\n";
    pt << left << setw(15) << "Name:" << p->name << "\n";//set width
    pt << setw(15) << "Passport:" << p->passport << "\n";
    pt << setw(15) << "Flight No:" << flight << "\n";
    pt << setw(15) << "From:" << depCity << "\n";
    pt << setw(15) << "To:" << destCity << "\n";
    pt << setw(15) << "Departure:" << time << "\n";
    pt << setw(15) << "Seat No:" << p->getSeatNumber() << "\n";
    pt << setw(15) << "Price:" << "$" << cost << "\n";
    pt << "----------------------------------------\n";
    pt.close();

    cout << "Ticket generated for " << p->name << "!\n";
}

void Tickets::displayTicket(Passenger* p) {
    string filename = "ticket_" + p->passport + ".txt";
    ifstream t(filename);

    if (!t.is_open()) {
        cout << "No ticket found for " << p->name << ".\n";
        return;
    }

    cout << "\n--- Your Boarding Pass ---\n";
    string line;
    while (getline(t, line)) {
        cout << line << "\n";
    }
    t.close();
}