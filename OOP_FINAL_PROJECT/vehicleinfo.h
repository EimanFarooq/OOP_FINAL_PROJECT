#ifndef VEHICLEINFO_H
#define VEHICLEINFO_H

#include "MyString.h"
#include <iostream>
using namespace std;

class VehicleInfo {
protected:
    MyString model;
    int capacity;

public:
    VehicleInfo(MyString m, int c) : model(m), capacity(c) {}
    virtual void display() const = 0;
    MyString getModel() const { return model; }
    int getCapacity() const { return capacity; }
    virtual ~VehicleInfo() {}
};

class Car : public VehicleInfo {
public:
    Car(MyString m, int c) : VehicleInfo(m, c) {}
    void display() const override {
        cout << "Car - Model: " << model << ", Capacity: " << capacity << endl;
    }
};

class Bike : public VehicleInfo {
public:
    Bike(MyString m, int c) : VehicleInfo(m, c) {}
    void display() const override {
        cout << "Bike - Model: " << model << ", Capacity: " << capacity << endl;
    }
};

class Rickshaw : public VehicleInfo {
public:
    Rickshaw(MyString m, int c) : VehicleInfo(m, c) {}
    void display() const override {
        cout << "Rickshaw - Model: " << model << ", Capacity: " << capacity << endl;
    }
};

#endif
