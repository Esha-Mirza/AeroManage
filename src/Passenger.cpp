#include "Passenger.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_PASSENGERS = 100;

void Passenger::registerUser() {
   
    ifstream infile("passenger.txt");
    Passenger passengers[MAX_PASSENGERS];
    int count = 0;
    
    while (infile >> passengers[count].name >> passengers[count].passport >> passengers[count].miles) {
        if (passengers[count].passport == passport) {
            cout << "Passenger with this passport already exists!\n";
            infile.close();
            return;
        }
        count++;
    }
    infile.close();

    if (count >= MAX_PASSENGERS) {
        cout << "Maximum passenger capacity reached!\n";
        return;
    }

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter passport number: ";
    cin >> passport;
    cout << "Enter initial miles: ";
    cin >> miles;

    for (int i = 0; i < count; i++) {
        if (passengers[i].passport == passport) {
            cout << "Passenger with this passport already exists!\n";
            return;
        }
    }

    ofstream outfile("passenger.txt", ios::app);
    outfile << name << " " << passport << " " << miles << endl;
    outfile.close();

    cout << "Passenger registered.\n";
}

void Passenger::login() {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter passport number: ";
    cin >> passport;

    ifstream infile("passenger.txt");
    string n, p;
    int m;
    bool found = false;
    
    while (infile >> n >> p >> m) {
        if (n == name && p == passport) {
            miles = m; 
            found = true;
            break;
        }
    }
    infile.close();
    
    if (found) {
        cout << "Login successful.\n";
    } else {
        cout << "Invalid credentials.\n";
    }
}