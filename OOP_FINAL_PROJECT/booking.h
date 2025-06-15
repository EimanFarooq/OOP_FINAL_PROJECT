#ifndef BOOKING_H
#define BOOKING_H

#include "RideOffer.h"
#include "Driver.h"
#include "MyString.h"
#include <iostream>

using namespace std;

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

    void display() const {
        cout << "Booking Info:\n";
        if (offer)
            offer->display();
        if (driver)
            driver->displayInfo();
        cout << "Rating: " << rating << ", Comment: " << comment << "\n";
    }

    Driver* getDriver() const {
        return driver;
    }

    RideOffer* getOffer() const {
        return offer;
    }
};

#endif

