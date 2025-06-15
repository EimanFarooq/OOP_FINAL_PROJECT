#ifndef VEHICLEINFO_H
#define VEHICLEINFO_H

#include "MyString.h"
#include <iostream>

class VehicleInfo {
protected:
    MyString model;
    int capacity;

public:
    VehicleInfo(MyString m, int c) : model(m), capacity(c) {}
    virtual void displayVehicle() const = 0;
    virtual ~VehicleInfo() {}
};

class Car : public VehicleInfo {
public:
    Car(MyString m, int c) : VehicleInfo(m, c) {}
    void displayVehicle() const override {
        cout << "Car - Model: " << model << ", Capacity: " << capacity << endl;
    }
};

class Bike : public VehicleInfo {
public:
    Bike(MyString m, int c) : VehicleInfo(m, c) {}
    void displayVehicle() const override {
        cout << "Bike - Model: " << model << ", Capacity: " << capacity << endl;
    }
};

class Rickshaw : public VehicleInfo {
public:
    Rickshaw(MyString m, int c) : VehicleInfo(m, c) {}
    void displayVehicle() const override {
        cout << "Rickshaw - Model: " << model << ", Capacity: " << capacity << endl;
    }
};

#endif
