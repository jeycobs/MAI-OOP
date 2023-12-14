#pragma once
#include <iostream>
//#include <cmath>
template <class T>
class Point2d {
    private:
        T _x, _y;

    public:
        Point2d() : _x(0), _y(0) {}
        Point2d(T x, T y) : _x(x), _y(y) {}
        Point2d(Point2d&& other) noexcept;

        void set(T x, T y);

        void x(T x);
        void y(T y);

        T x() const;
        T y() const;

        T distanceTo(const Point2d& other) const;
        T dotProduct(const Point2d& other) const;

        bool operator==(const Point2d& other) const;
        
        friend const Point2d operator+(const Point2d& p1, const Point2d& p2) {
            return Point2d<T>(p1._x + p2._x, p1._y + p2._y);
        }
        friend const Point2d operator-(const Point2d& p1, const Point2d& p2) {
            return Point2d<T>(p1._x - p2._x, p1._y - p2._y);
        }

        Point2d& operator=(const Point2d& other);

        friend std::istream& operator>>(std::istream& is, Point2d& point) {
            double x, y;
            char comma;
            is >> x >> comma >> y;
            point.set(x, y);
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, const Point2d& point) {
            os << '(' << point.x() << " , " << point.y() << ')';
            return os;
        }   
    
};
#include "../templates/point2d.cpp"
