#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include "Booking.h"
#include "VehicleInfo.h"
#include "MyVector.h"

class Driver : public Person {
private:
    MyVector<Booking*> bookings;
    MyVector<int> availability;
    bool authenticated;
    VehicleInfo* vehicle;

public:
    Driver(MyString f, MyString l, MyString e, MyString p, MyString a, VehicleInfo* v)
        : Person(f, l, e, p, a, DRIVER), vehicle(v), authenticated(false) {}

    void addAvailability(int timeSlot) {
        availability.push_back(timeSlot);
    }

    void bookRide(Booking* booking) {
        bookings.push_back(booking);
    }

    void displayInfo() const override {
        cout << "Driver: " << getFullName() << endl;
        if (vehicle) vehicle->display();
    }
};

#endif

