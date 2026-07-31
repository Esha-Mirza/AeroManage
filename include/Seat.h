

#ifndef SEAT_H
#define SEAT_H

class Booking;

class Seat {
public:
    int seatPrice(bool isWindow);
    void occupySeat(Booking*, int);
};


#endif
