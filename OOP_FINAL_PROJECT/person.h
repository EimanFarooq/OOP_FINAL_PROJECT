#ifndef PERSON_H
#define PERSON_H

#include "MyString.h"
#include <iostream>
using namespace std;

enum UserType { PARENT, DRIVER };

class Person {
protected:
    MyString firstName;
    MyString lastName;
    MyString email;
    MyString phoneNumber;
    MyString address;
    UserType userType;

public:
    Person(MyString f, MyString l, MyString e, MyString p, MyString a, UserType u)
        : firstName(f), lastName(l), email(e), phoneNumber(p), address(a), userType(u) {}

    virtual void displayInfo() const = 0;

    MyString getFullName() const {
        MyString full = firstName;
        full = full + " " + lastName;
        return full;
    }

    UserType getUserType() const { 
        return userType;
    }

    virtual ~Person() {}
};

#endif

