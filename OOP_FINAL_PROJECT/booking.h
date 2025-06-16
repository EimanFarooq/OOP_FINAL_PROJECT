#ifndef BOOKING_H
#define BOOKING_H

#include "RideOffer.h"
#include "MyString.h"
#include <iostream>
class Driver; 

class Booking {
private:
    RideOffer* offer;
    Driver* driver;
    int rating;
    MyString comment;

public:
    Booking(RideOffer* o, Driver* d)
        : offer(o), driver(d), rating(0), comment("") {}

    void setRating(int r, MyString c) {
        rating = r;
        comment = c;
    }

    void display() const; 

    Driver* getDriver() const {
        return driver;
    }

    RideOffer* getOffer() const {
        return offer;
    }
};

#endif
