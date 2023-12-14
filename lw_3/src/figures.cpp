#include "../include/figures.hpp"

//1) Rectangle
Rectangle::Rectangle() : a(0,0), b(0,0), c(0,0), d(0,0),
                            sideA(0), sideB(0) {}

Rectangle::Rectangle(const Rectangle& other) {
    _copy(other);
}

void Rectangle::printVertices(std::ostream& os) const { //вывод
    os << "1ая вершина: " << a << std::endl;
    os << "2ая вершина: " << b << std::endl;
    os << "3ая вершина: " << c << std::endl;
    os << "4ая вершина: " << d << std::endl;
}

void Rectangle::readVertices(std::istream& is) {    //чтение
    std::cout << "Введи координаты 1 вершины: ";
    is >> a;
    std::cout << "Введи координа 2 вершины: ";
    is >> b;
    std::cout << "Введи координаты 3 вершины:  ";
    is >> c;
    std::cout << "Введи координаты 4 вершины: ";
    is >> d;
    double lA = a.distanceTo(b);
    double lB = b.distanceTo(c);
    double lC = c.distanceTo(d);
    double lD = d.distanceTo(a);

    if (lA != lC || lB != lD) {
        std::cerr << "The entered coordinates do not form a rectangle." << std::endl;
    }
}

Figure& Rectangle::_copy(const Figure& other) {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (otherRect) {
        a = otherRect->a;
        b = otherRect->b;
        c = otherRect->c;
        d = otherRect->d;
    }
    return *this;
}

Figure& Rectangle::_move(Figure& other) {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (otherRect) {
        a = std::move(otherRect->a);
        b = std::move(otherRect->b);
        c = std::move(otherRect->c);
        d = std::move(otherRect->d);
    }
    return *this;
}

Point2d Rectangle::center() {
    double centerX = (a.x() + c.x()) / 2.0;
    double centerY = (a.y() + c.y()) / 2.0;
    return Point2d(centerX, centerY);
}

bool Rectangle::isSameAs(const Figure& other) const {
    const Rectangle* otherRect = dynamic_cast<const Rectangle*>(&other);
    if (otherRect){
        return (a == otherRect->a && b == otherRect->b 
             && c == otherRect->c && d == otherRect->d);
    }
    return false;
}

double Rectangle::getArea() const {
    double lA = a.distanceTo(b);
    double lB = b.distanceTo(c);
    return lA * lB;
}


//2) trapezoid

Trapezoid::Trapezoid() : a(0,0), b(0,0), c(0,0), d(0,0),
                            sideA(0), sideB(0) {}

Trapezoid::Trapezoid(const Trapezoid& other) {
    _copy(other);
}

void Trapezoid::printVertices(std::ostream& os) const {
    os << "1ая вершина: " << a << std::endl;
    os << "2ая вершина: " << b << std::endl;
    os << "3ая вершина: " << c << std::endl;
    os << "4ая вершина: " << d << std::endl;
 
}

void Trapezoid::readVertices(std::istream& is) {
   std::cout << "Введи координаты 1 вершины: ";
    is >> a;
    std::cout << "Введи координа 2 вершины: ";
    is >> b;
    std::cout << "Введи координаты 3 вершины:  ";
    is >> c;
    std::cout << "Введи координаты 4 вершины: ";
    is >> d; 
    double lA = a.distanceTo(b);
    double lB = b.distanceTo(c);
    double lC = c.distanceTo(d);
    double lD = d.distanceTo(a);

    if (lA != lC || lB != lD) { //?
        std::cerr << "The entered coordinates do not form a rectangle." << std::endl;
    }
}

Figure& Trapezoid::_copy(const Figure& other) {
    const Trapezoid* otherRect = dynamic_cast<const Trapezoid*>(&other);
    if (otherRect) {
        a = otherRect->a;
        b = otherRect->b;
        c = otherRect->c;
        d = otherRect->d;
    }
    return *this;
}

Figure& Trapezoid::_move(Figure& other) {
    const Trapezoid* otherRect = dynamic_cast<const Trapezoid*>(&other);
    if (otherRect) {
        a = std::move(otherRect->a);
        b = std::move(otherRect->b);
        c = std::move(otherRect->c);
        d = std::move(otherRect->d);
    }
    return *this;
}

Point2d Trapezoid::center() {   
    double centerX = (a.x() + b.x() + c.x() + d.x()) / 4.0;
    double centerY = (a.y() + b.y() + c.y() + d.y()) / 4.0;
    return Point2d(centerX, centerY);
}

bool Trapezoid::isSameAs(const Figure& other) const {
    const Trapezoid* otherRect = dynamic_cast<const Trapezoid*>(&other);
    if (otherRect){
        return (a == otherRect->a && b == otherRect->b 
             && c == otherRect->c && d == otherRect->d);
    }
    return false;
}

double Trapezoid::getArea() const { //площадь
    double AB = a.distanceTo(b);    //верхнее основание
    double DC = d.distanceTo(c);    //нижнее основание
    double AD = a.distanceTo(d);    //левый бок
    double BC = b.distanceTo(c);    //првый бок
    //формула нахождения высоты
    
    //double h = std::sqrt(std::pow(AD,2) - std::pow(((std::pow((DC - AB),2)) + std::pow(AD,2)-std::pow(BC,2 )/(2*(DC-AB))),2));
    double c2 = AD*AD;
    double a_b2 = std::pow(DC-AB,2);
    double a_b = DC -AB;
    double d2 = BC * BC;
    double h = sqrt(c2 - std::pow(((a_b2+c2-d2)/(2*a_b)),2));
    return ((AB + DC)/2)*h;
}

//3 Rhomb

Rhomb::Rhomb() : a(0,0), b(0,0), c(0,0), d(0,0),
                            sideA(0), sideB(0) {}

Rhomb::Rhomb(const Rhomb& other) {
    _copy(other);
}

void Rhomb::printVertices(std::ostream& os) const {
    os << "1ая вершина: " << a << std::endl;
    os << "2ая вершина: " << b << std::endl;
    os << "3ая вершина: " << c << std::endl;
    os << "4ая вершина: " << d << std::endl;
}

void Rhomb::readVertices(std::istream& is) {
    std::cout << "Введи координаты 1 вершины: ";
    is >> a;
    std::cout << "Введи координа 2 вершины: ";
    is >> b;
    std::cout << "Введи координаты 3 вершины:  ";
    is >> c;
    std::cout << "Введи координаты 4 вершины: ";
    is >> d;
    double lA = a.distanceTo(b);
    double lB = b.distanceTo(c);
    double lC = c.distanceTo(d);
    double lD = d.distanceTo(a);

    if (lA != lC || lB != lD) { //?
        std::cerr << "The entered coordinates do not form a rectangle." << std::endl;
    }
}

Figure& Rhomb::_copy(const Figure& other) {
    const Rhomb* otherRect = dynamic_cast<const Rhomb*>(&other);
    if (otherRect) {
        a = otherRect->a;
        b = otherRect->b;
        c = otherRect->c;
        d = otherRect->d;
    }
    return *this;
}

Figure& Rhomb::_move(Figure& other) {
    const Trapezoid* otherRect = dynamic_cast<const Trapezoid*>(&other);
    if (otherRect) {
        a = std::move(otherRect->a);
        b = std::move(otherRect->b);
        c = std::move(otherRect->c);
        d = std::move(otherRect->d);
    }
    return *this;
}

Point2d Rhomb::center() {   
    double centerX = (a.x() + b.x()) / 2.0;
    double centerY = (a.y() + b.y()) / 2.0;
    return Point2d(centerX, centerY);
}

bool Rhomb::isSameAs(const Figure& other) const {
    const Rhomb* otherRect = dynamic_cast<const Rhomb*>(&other);
    if (otherRect){
        return (a == otherRect->a && b == otherRect->b 
             && c == otherRect->c && d == otherRect->d);
    }
    return false;
}

double Rhomb::getArea() const { //площадь
    //найдем диагонали
    double AC = a.distanceTo(c);
    double BD = b.distanceTo(d);
    return 0.5 * AC * BD;     
}