#ifndef RIDEOFFER_H
#define RIDEOFFER_H

#include "MyString.h"
#include <ctime>
#include "Logger.h"
#include <iostream>

using namespace std;

class Booking; // Forward declaration
class Parent;

class RideOffer {
private:
    MyString pickupLocation;
    MyString dropoffLocation;
    tm rideTime;
    Booking* booking;
    Parent* owner;

public:
    RideOffer(MyString pickup, MyString drop, tm time, Parent* p)
        : pickupLocation(pickup), dropoffLocation(drop), rideTime(time), booking(nullptr), owner(p) {
        Logger::logEvent("RideOffer created.");
    }

    bool isBooked() const {
        return booking != nullptr;
    }

    void setBooking(Booking* b) {
        booking = b;
        Logger::logEvent("RideOffer booked.");
    }

    tm getRideTime() const { return rideTime; }
    Parent* getOwner() const { return owner; }
    MyString getPickupLocation() const { return pickupLocation; }
    MyString getDropoffLocation() const { return dropoffLocation; }

    void display() const {
        cout << "Ride from " << pickupLocation << " to " << dropoffLocation << " at ";
        char timeStr[26];
        asctime_s(timeStr, sizeof(timeStr), &rideTime);
        cout << timeStr;
        cout << (isBooked() ? "Status: Booked\n" : "Status: Available\n");
    }
};

#endif
