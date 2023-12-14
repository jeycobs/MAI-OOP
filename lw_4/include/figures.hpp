#include "figure.hpp"
//#include "../templates/figures.cpp"
//#include "/point2d.hpp"
template <class T>
class Rectangle : public Figure {
    public:
        Point2d<T> a;
        Point2d<T> b;
        Point2d<T> c;
        Point2d<T> d;
        Rectangle();
        Rectangle(const Rectangle& other);
        ~Rectangle() = default;

        Point2d<T> center() ;
       
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

template <class T>
class Trapezoid : public Figure {
    public:
        Point2d<T> a;
        Point2d<T> b;
        Point2d<T> c;
        Point2d<T> d;
        Trapezoid();
        Trapezoid(const Trapezoid& other);
        ~Trapezoid() = default;

        Point2d<T> center();

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

template <class T>
class Rhomb : public Figure {
    public:
        Point2d<T> a;
        Point2d<T> b;
        Point2d<T> c;
        Point2d<T> d;
        Rhomb();
        Rhomb(const Rhomb& other);
        ~Rhomb() = default;

        Point2d<T> center();

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

 #include "../templates/figures.cpp"
