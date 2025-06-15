#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

class MyString {
private:
    char* data;
    int length;

public:
    MyString() : data(nullptr), length(0) {}

    MyString(const char* str) {
        length = 0;
        while (str[length] != '\0') length++;
        data = new char[length + 1];
        for (int i = 0; i < length; i++) data[i] = str[i];
        data[length] = '\0';
    }

    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        for (int i = 0; i < length; i++) data[i] = other.data[i];
        data[length] = '\0';
    }

    ~MyString() {
        delete[] data;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            for (int i = 0; i < length; i++) data[i] = other.data[i];
            data[length] = '\0';
        }
        return *this;
    }

    MyString operator+(const MyString& other) const {
        int newLen = length + other.length;
        char* newData = new char[newLen + 1];
        for (int i = 0; i < length; i++)
            newData[i] = data[i];
        for (int i = 0; i < other.length; i++)
            newData[length + i] = other.data[i];
        newData[newLen] = '\0';
        MyString result(newData);
        delete[] newData;
        return result;
    }

    MyString operator+(const char* other) const {
        int otherLen = 0;
        while (other[otherLen] != '\0') otherLen++;
        int newLen = length + otherLen;
        char* newData = new char[newLen + 1];
        for (int i = 0; i < length; i++)
            newData[i] = data[i];
        for (int i = 0; i < otherLen; i++)
            newData[length + i] = other[i];
        newData[newLen] = '\0';
        MyString result(newData);
        delete[] newData;
        return result;
    }

    friend ostream& operator<<(ostream& os, const MyString& str) {
        os << str.data;
        return os;
    }
};

#endif
