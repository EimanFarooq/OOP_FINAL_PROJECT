#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class MyVector {
    T* data;
    int capacity;
    int length;

    void resize() {
        int newCap = capacity * 2;
        T* newData = new T[newCap];
        for (int i = 0; i < length; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    MyVector() : capacity(10), length(0) {
        data = new T[capacity];
    }

    MyVector(const MyVector& other) : capacity(other.capacity), length(other.length) {
        data = new T[capacity];
        for (int i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            length = other.length;
            data = new T[capacity];
            for (int i = 0; i < length; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if (length >= capacity) resize();
        data[length++] = value;
    }

    int size() const {
        return length;
    }

    T& operator[](int index) {
#ifndef NDEBUG
        if (index < 0 || index >= length) {
            cerr << "Index out of bounds in MyVector: " << index << endl;
            exit(1);
        }
#endif
        return data[index];
    }

    const T& operator[](int index) const {
#ifndef NDEBUG
        if (index < 0 || index >= length) {
            cerr << "Index out of bounds in const MyVector: " << index << endl;
            exit(1);
        }
#endif
        return data[index];
    }

    ~MyVector() {
        delete[] data;
    }
};

#endif
