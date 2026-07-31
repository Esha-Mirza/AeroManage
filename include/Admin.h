
#ifndef ADMIN_H
#define ADMIN_H

#include "Staff.h"
#include "User.h"
#include <string>
#include<iostream>
using namespace std;
class Admin : public User, public Staff {
public:
    string name;
    int id;
    void registerUser();
    void login();
    void markAttendance();
    void addFlight();
};

#endif

