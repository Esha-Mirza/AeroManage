

#include "CarryLuggage.h"
#include "Payment.h"
#include <iostream>

using namespace std;

void CarryLuggage::chargeFee(Payment* pay) //association with payment
{
    char confirm;
    cout << "Luggage fee is Rs. 200. Do you want to continue? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        cout << "Charging luggage fee...\n";
        pay->total += fee;
    } else {
        cout << "Luggage fee skipped.\n";
    }
}
