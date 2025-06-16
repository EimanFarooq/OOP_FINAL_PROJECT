#ifndef DRIVER_H 
#define DRIVER_H

#include "Person.h"
#include "Booking.h"
#include "VehicleInfo.h"
#include "MyVector.h"
#include <iostream>

using namespace std;

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

    void addBooking(Booking* b) {
        bookings.push_back(b);
    }

    void displayInfo() const override {
        cout << "Driver: " << getFullName() << endl;
        cout << "Email: " << email << ", Phone: " << phoneNumber << ", Address: " << address << endl;
        if (vehicle) {
            vehicle->display();
        }

        cout << "Bookings:\n";
        for (int i = 0; i < bookings.size(); ++i) {
            if (bookings[i]) {
                bookings[i]->display();
            }
        }
    }
};

#endif
