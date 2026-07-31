
#include "MealSelection.h"
#include <iostream>

using namespace std;

void MealSelection::selectType() {
    cout << "Select meal: 1. Veg  2. Non-veg: ";
    int choice;
    cin >> choice;
    type = (choice == 1) ? "Veg" : "Non-veg";


}

