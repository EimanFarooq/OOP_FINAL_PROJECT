#ifndef CHILD_H
#define CHILD_H

#include "MyString.h"
#include "MyVector.h"
#include <iostream>

using namespace std;

class Parent; 

class Child {
private:
    MyString name;
    int age;
    MyVector<MyString> emergencyContacts;
    Parent* parent;

public:
    Child(MyString name, int age, Parent* p)
        : name(name), age(age), parent(p) {}

    void addEmergencyContact(MyString contact) {
        emergencyContacts.push_back(contact);
    }

    void display() const {
        cout << "Child: " << name << ", Age: " << age << "\n";
        cout << "Emergency Contacts:\n";
        for (int i = 0; i < emergencyContacts.size(); ++i) {
            cout << "- " << emergencyContacts[i] << "\n";
        }
    }
};

#endif
