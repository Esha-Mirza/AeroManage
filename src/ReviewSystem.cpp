

#include "ReviewSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

void ReviewSystem::leaveReview() {
    string review;
    cout << "Leave your review: ";
    cin.ignore();
    getline(cin, review);
    ofstream f("reviews.txt", ios::app);
    f << review << endl;
    cout << "Thanks for your review!\n";
}
