#ifndef DRIVER_H
#define DRIVER_H

#include "Person.h"
#include "VehicleInfo.h"
#include "Booking.h"
#include "MyVector.h"

class Driver : public Person {
private:
    MyVector<Booking*> bookings;
    MyVector<int> availability; // Placeholder for available time slots
    VehicleInfo* vehicle;

public:
    Driver(MyString f, MyString l, MyString e, MyString p, MyString a, VehicleInfo* v)
        : Person(f, l, e, p, a, DRIVER), vehicle(v) {}  // Passes UserType

    void addAvailability(int slot) {
        availability.push_back(slot);
    }

    void displayInfo() const override {
        cout << "Driver: " << getFullName() << endl;  // ✅ Removed .c_str()
    }
};

#endif
