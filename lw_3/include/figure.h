#pragma once

#include <iostream>
#include <ostream>
#include "vector.h"
class Figure{
    private:
        Vector massive;
    public:
        Figure();
        ~Figure();

        virtual void geometryFigureCenter();
        std::ostream& operator <<(int top);
        std::istream& operator >>(int index);
        operator double();
};