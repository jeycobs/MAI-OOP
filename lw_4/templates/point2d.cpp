#include <cmath>
#include <iostream>

template <class T>
Point2d<T>::Point2d(Point2d&& other) noexcept {
    _x = std::move(other._x);
    _y = std::move(other._y);
}

template <class T>
void Point2d<T>::set(T x, T y) {
    this->x(x);
    this->y(y);
}

template <class T>
void Point2d<T>::x(T x) {
    this->_x = x;
}

template <class T>
void Point2d<T>::y(T y) {
    this->_y = y;
}

template <class T>
T Point2d<T>::x() const {
    return _x;
}

template <class T>
T Point2d<T>::y() const {
    return _y;
}

template <class T>
T Point2d<T>::distanceTo(const Point2d& other) const {
    T dx = _x - other._x;
    T dy = _y - other._y;
    return std::sqrt(dx * dx + dy * dy);
}

template <class T>
T Point2d<T>::dotProduct(const Point2d& other) const {
    return x() * other.x() + y() * other.y();
}

template <class T>
bool Point2d<T>::operator==(const Point2d& other) const {
    return _x == other._x && _y == other._y;
}

template <class T>
Point2d<T>& Point2d<T>::operator=(const Point2d& other) {
    x(other.x());
    y(other.y());
    return *this;
}
