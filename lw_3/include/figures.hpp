#include "./figure.h"
#include "point2d.hpp"

class Rectangle : public Figure {
    public:
        Point2d a;
        Point2d b;
        Point2d c;
        Point2d d;
        Rectangle();
        Rectangle(const Rectangle& other);
        ~Rectangle() = default;

        Point2d center() override;
       
    protected:
        void printVertices(std::ostream& os) const override;
        void readVertices(std::istream& is) override;
        Figure& _copy(const Figure& other) override;
        Figure& _move(Figure& other) override;
        bool isSameAs(const Figure& other) const override;
        double getArea() const override; 

    private:
        double sideA;
        double sideB;
    
};
class Trapezoid : public Figure {
    public:
        Point2d a;
        Point2d b;
        Point2d c;
        Point2d d;
        Trapezoid();
        Trapezoid(const Trapezoid& other);
        ~Trapezoid() = default;

        Point2d center() override;

    protected:
        void printVertices(std::ostream& os) const override;
        void readVertices(std::istream& is) override;
        Figure& _copy(const Figure& other) override;
        Figure& _move(Figure& other) override;
        bool isSameAs(const Figure& other) const override;
        double getArea() const override;

    private:
        double sideA;
        double sideB;
        double sideC;
        double sideD;
};

class Rhomb : public Figure {
    public:
        Point2d a;
        Point2d b;
        Point2d c;
        Point2d d;
        Rhomb();
        Rhomb(const Rhomb& other);
        ~Rhomb() = default;

        Point2d center() override;

    protected:
        void printVertices(std::ostream& os) const override;
        void readVertices(std::istream& is) override;
        Figure& _copy(const Figure& other) override;
        Figure& _move(Figure& other) override;
        bool isSameAs(const Figure& other) const override;
        double getArea() const override;

    private:
        double sideA;
        double sideB;
        double sideC;
        double sideD;
};
