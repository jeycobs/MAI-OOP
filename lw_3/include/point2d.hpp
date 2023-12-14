#pragma once
#include <cmath>
#include <iostream>

class Point2d {
    private:
        double _x, _y;

    public:
        Point2d();
        Point2d(double x, double y);
        Point2d(Point2d&& other) noexcept;

        void set(double x, double y);

        void x(double x);
        void y(double y);

        double x() const;
        double y() const;

        double distanceTo(const Point2d& other) const;
        double dotProduct(const Point2d& other) const;

        bool operator==(const Point2d& other) const;
        
        friend const Point2d operator+(const Point2d& p1, const Point2d& p2);
        friend const Point2d operator-(const Point2d& p1, const Point2d& p2);

        Point2d& operator=(const Point2d& other);

        friend std::istream& operator>>(std::istream& is, Point2d& point);
        friend std::ostream& operator<<(std::ostream& os, const Point2d& point);
        
    
};