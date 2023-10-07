#pragma once

#include <iostream>
#include "./vector.h"

class Octal{
    private:
        //int decimal;
        Vector content;
        //Vector content1, content2;
    public:
        Octal();
        //Octal(int decimal);
        //Octal(Vector content);
        //Octal(Vector content1, Vector content2);
        Octal(int number);
        ~Octal();

        void print();
        void set(int number);
        //std::string get();
        int decimalSystemTranslate(Vector content);
        bool moreOrEquals(Vector content1, Vector content2);
};