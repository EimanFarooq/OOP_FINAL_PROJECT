#ifndef BOOKING_H
#define BOOKING_H

#include "Driver.h"
#include "RideOffer.h"
#include "Logger.h"

class Booking {
private:
    int rating;
    MyString comment;
    RideOffer* ride;
    Driver* driver;

public:
    Booking(RideOffer* r, Driver* d) : ride(r), driver(d), rating(0) {
        Logger::logEvent("Booking created.");
    }

    void setRating(int r, MyString c) {
        rating = r;
        comment = c;
        Logger::logEvent("Booking rated.");
    }
};

#endif
