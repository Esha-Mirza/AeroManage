
#include <iostream>
#include <fstream>
#include "Payment.h"

using namespace std;

void Payment::receivePayment() {
    double pay;
    cout << "Total amount due: Rs. " << total << endl;
    cout << "Enter payment amount: ";
    cin >> pay;
    while (pay < total) {
        cout << "Insufficient amount! Try again: ";
        cin >> pay;
    }
    cout << "Payment accepted. Change returned: Rs. " << (pay - total) << endl;

}
