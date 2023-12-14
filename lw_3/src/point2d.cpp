#include "../include/point2d.hpp"

Point2d::Point2d() : _x(0), _y(0) {};

Point2d::Point2d(double x, double y) : _x(x), _y(y) {};

Point2d::Point2d(Point2d&& other) noexcept {
    _x = std::move(other._x);
    _y = std::move(other._y);
}

void Point2d::set(double x, double y) {
    this->x(x);
    this->y(y);
}

void Point2d::x(double x) {
    this->_x = x;
}

void Point2d::y(double y) {
    this->_y = y;
}

double Point2d::x() const {
    return _x;
}

double Point2d::y() const {
    return _y;
}

double Point2d::distanceTo(const Point2d& other) const {    //дистанция по школьной ф-ле
    double dx = _x - other._x;
    double dy = _y - other._y;
    return std::sqrt(dx * dx + dy * dy);
}

double Point2d::dotProduct(const Point2d& other) const {
    return x() * other.x() + y() * other.y();
}

bool Point2d::operator==(const Point2d& other) const {
    return _x == other._x && _y == other._y;
}

Point2d& Point2d::operator=(const Point2d& other) {
    x(other.x());
    y(other.y());
    return *this;
}

// Overloaded addition operator
const Point2d operator+(const Point2d& p1, const Point2d& p2) {
    return Point2d(p1._x + p2._x, p1._y + p2._y);
}

// Overloaded subtraction operator
const Point2d operator-(const Point2d& p1, const Point2d& p2) {
    return Point2d(p1._x - p2._x, p1._y - p2._y);
}

std::istream& operator>>(std::istream& is, Point2d& point) {
    double x, y;
    char comma;
    is >> x >> comma >> y;
    point.set(x, y);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point2d& point) {
    os << '(' << point.x() << " , " << point.y() << ')';
    return os;
}