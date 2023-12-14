#include <iostream>
#include "include/point2d.hpp"
#include "include/figures.hpp"
#include "include/vector.hpp"

int main(int argc, char** argv) {


    Rectangle rec;

    rec.a = Point2d(0, 0);
    rec.b = Point2d(0, 3);
    rec.c = Point2d(1, 3);
    rec.d = Point2d(1, 0);

    //std::cin >> rect;

    //std::cout << rect;
    std::cout << "Прямоугольник" << std::endl;
    std::cout << rec.center() << std::endl;
    std::cout << double(rec) << std::endl;
    
    std::cout << "Трапеция" << std::endl;

    Trapezoid tr;

    tr.a = Point2d(5,6);    
    tr.b = Point2d(10,6);
    tr.c = Point2d(10,1);
    tr.d = Point2d(1,1);
    std::cout << rec.center() << std::endl; 
    std::cout << double(rec) << std::endl;

    std::cout << "Ромб" << std::endl; 
    Rhomb rh;

    rh.a = Point2d(1,6);
    rh.b = Point2d(4,10);
    rh.c = Point2d(7,6);
    rh.d = Point2d(4,2);
    std::cout << rh.center() << std::endl;
    std::cout << double(rh) << std::endl;

    Vector<Figure*> figures;

    figures.push_back(&rec);
    figures.push_back(&tr);
    figures.push_back(&rh);

    std::cout <<"Геом. центр прямоугольник " << figures[0]->center() << std::endl;    
    std::cout << "Площадь прямоугольника " <<double(*figures[0]) << std::endl;    
    double resultArea = 0;
    //std::cout << "Площадь трапеции " << double(*figures[1]) << std::endl;
    for (const auto& cycle : figures) {
        resultArea += double(*cycle);
    }
    std::cout << "Общая площадь: " << resultArea << std::endl; 
    return 0;
}
