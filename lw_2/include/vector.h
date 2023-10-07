#pragma once

#include <iostream>

class Vector{
    private:

        size_t vectorSize;
        size_t capacity;
        unsigned char* data;
    public:
        Vector();
        Vector(std::string number);
        Vector(const size_t capacity);
        ~Vector();
        //Vector(int number);


        bool isEmpty() const;
        int push_back(unsigned char number);
        int reserve(size_t capacity);
        int reverse();
        int clear();
        void set(std::string number);
        size_t size() const;
        unsigned char operator[](size_t index);


};