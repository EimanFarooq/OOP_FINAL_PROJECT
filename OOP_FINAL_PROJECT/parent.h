#ifndef PARENT_H
#define PARENT_H

#include "Person.h"
#include "Child.h"
#include "RideOffer.h"
#include "MyVector.h"

class Parent : public Person {
private:
    MyVector<Child*> children;
    MyVector<RideOffer*> rideOffers;

public:
    Parent(MyString f, MyString l, MyString e, MyString p, MyString a)
        : Person(f, l, e, p, a, PARENT) {}  // Passes UserType

    void addChild(Child* child) {
        children.push_back(child);
    }

    void createRideOffer(RideOffer* offer) {
        rideOffers.push_back(offer);
    }

    void displayInfo() const override {
        cout << "Parent: " << getFullName() << endl;  // ✅ Removed .c_str()
    }
};

#endif
