#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <iostream>
using namespace std;

class MyString {
    char* data;

public:
    MyString() : data(nullptr) {}

    MyString(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    MyString(const MyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const MyString& str) {
        os << str.data;
        return os;
    }

    ~MyString() {
        delete[] data;
    }
};

#endif
