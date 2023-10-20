#pragma once 
#include "figure.h"

class Rectangle : Figure{
    private:
        Vector massive;
    public:
        Rectangle();
        ~Rectangle();
        void geometryFigureCenter() override;
        std::ostream& operator <<(int top);
        std::istream& operator >>(int index);
        operator double();

};