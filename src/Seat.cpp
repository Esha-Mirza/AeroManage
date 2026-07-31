
#include "Seat.h"
#include "Booking.h"

int Seat::seatPrice(bool isWindow) {
    return isWindow ? 1200 : 1000;
}

void Seat::occupySeat(Booking* b, int index) {
    b->seats[index] = '1';
}