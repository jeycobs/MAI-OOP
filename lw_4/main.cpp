#include <iostream>
#include <memory>
#include "include/point2d.hpp"
#include "include/figures.hpp"
#include "include/vector.hpp"

int main(int argc, char** argv) {


    Rectangle<double> rec;

    rec.a = Point2d(0.0, 0.0);
    rec.b = Point2d(0.0, 3.0);
    rec.c = Point2d(1.0, 3.0);
    rec.d = Point2d(1.0, 0.0);

    //std::cin >> rect;

    //std::cout << rect;
    std::cout << "Прямоугольник" << std::endl;
    std::cout << rec.center() << std::endl;
    std::cout << double(rec) << std::endl;
    
    std::cout << "Трапеция" << std::endl;

    Trapezoid<double> tr;

    tr.a = Point2d(5.0,6.0);    
    tr.b = Point2d(10.0,6.0);
    tr.c = Point2d(10.0,1.0);
    tr.d = Point2d(1.0,1.0);
    std::cout << rec.center() << std::endl; 
    std::cout << double(rec) << std::endl;

    std::cout << "Ромб" << std::endl; 
    Rhomb<double> rh;

    rh.a = Point2d(1.0,6.0);
    rh.b = Point2d(4.0,10.0);
    rh.c = Point2d(7.0,6.0);
    rh.d = Point2d(4.0,2.0);
    std::cout << rh.center() << std::endl;
    std::cout << double(rh) << std::endl;

    Vector<std::shared_ptr<Figure>> figures;

    figures.push_back(std::make_shared<Rectangle<double>>(rec));
    figures.push_back(std::make_shared<Trapezoid<double>>(tr));
    figures.push_back(std::make_shared<Rhomb<double>>(rh));

    std::cout << "Площадь прямоугольника " <<double(*figures[0]) << std::endl;    
    double resultArea = 0;
    //std::cout << "Площадь трапеции " << double(*figures[1]) << std::endl;
    for (const auto& cycle : figures) {
        resultArea += double(*cycle);
    }
    std::cout << "Общая площадь: " << resultArea << std::endl; 
    return 0;
}