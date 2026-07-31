#include "Admin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ADMINS = 5;

void Admin::registerUser() {
    ifstream infile("admins.txt");
    Admin admins[MAX_ADMINS];
    int count = 0;

    while (infile >> admins[count].name >> admins[count].id) {
        count++;
    }
    infile.close();

    if (count >= MAX_ADMINS) {
        cout << "Max 5 admins allowed.\n";
        return;
    }

    cout << "Enter admin name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;


    for (int i = 0; i < count; i++) {
        if (admins[i].id == id) {
            cout << "Admin with this ID already exists!\n";
            return;
        }
    }

    ofstream outfile("admins.txt", ios::app);
    outfile << name << " " << id << endl;
    outfile.close();

    cout << "Admin registered.\n";
}

void Admin::login() {
    cout << "Enter admin name: ";
    cin >> name;
    cout << "Enter ID: ";
    cin >> id;

    ifstream infile("admins.txt");
    string n;
    int i;
    bool found = false;

    while (infile >> n >> i) {
        if (n == name && i == id) {
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

void Admin::markAttendance() {
    cout << "Admin has been marked present!\n";
}

void Admin::addFlight() //association
{
    string id, dep, dest, t, miles;
    cout << "Enter Flight ID: ";
    cin >> id;
    cout << "Departure City: ";
    cin >> dep;
    cout << "Destination City: ";
    cin >> dest;
    cout << "Departure Time: ";
    cin >> t;
    cout << "Enter miles: ";
    cin >> miles;

    ofstream fout("flights.txt", ios::app);
    fout << id << " " << dep << " " << dest << " " << t << " " << miles << endl;
    fout.close();
    cout << "Flight added!\n";
}