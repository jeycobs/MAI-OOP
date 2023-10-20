#pragma once

#include <iostream>

class Vector{
    private:
        unsigned char* data;
        size_t vector_size;
        size_t capacity;
    public:
        Vector();
        ~Vector();
        Vector(const Vector& a);
        void add(int newElement);    
        size_t size() const;    
        void clear();    
        bool isEmpty(); 
        void resize(int size);   
        void reverse();  //для перевода из 10 в 8 сис. счисления
        std::string print() const;
        unsigned char& operator [](int index);
};

