#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include "Booking.h"
#include "MyVector.h"
#include "VehicleInfo.h"
#include <ctime>

class Driver : public Person {
private:
    MyVector<Booking*> bookings;
    MyVector<int> availability; // Simplified for demo: replace with custom time range
    bool authenticated;
    VehicleInfo* vehicle;

public:
    Driver(MyString f, MyString l, MyString e, MyString p, MyString a, VehicleInfo* v)
        : Person(f, l, e, p, a, DRIVER), authenticated(false), vehicle(v) {}

    void addAvailability(int timeSlot) {
        availability.push_back(timeSlot);
    }

    void displayInfo() const override {
        cout << "Driver: " << getFullName() << endl;
    }

    void bookRide(Booking* booking) {
        bookings.push_back(booking);
    }
};

#endif
