

#ifndef CARRYLUGGAGE_H
#define CARRYLUGGAGE_H


class Payment;

class CarryLuggage {
public:
    int fee = 200;
    void chargeFee(Payment*);
};


#endif
