#ifndef CHILD_H
#define CHILD_H

#include "MyString.h"
#include <iostream>
#include "Logger.h"

class Parent; // Forward declaration

class Child {
private:
    int age;
    MyVector<MyString> emergencyContacts;
    Parent* parent;

public:
    Child(int a, Parent* p) : age(a), parent(p) {}

    void addEmergencyContact(MyString contact) {
        emergencyContacts.push_back(contact);
        Logger::logEvent("Emergency contact added for child.");
    }
};

#endif
