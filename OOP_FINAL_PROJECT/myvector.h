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

    void push_back(const T& value) {
        if (length >= capacity) resize();
        data[length++] = value;
    }

    int size() const {
        return length;
    }

    T& operator[](int index) {
        return data[index];
    }

    ~MyVector() {
        delete[] data;
    }
};

#endif
