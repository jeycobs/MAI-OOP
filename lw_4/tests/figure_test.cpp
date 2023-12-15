#include "gtest/gtest.h"
#include "sstream"
#include "../include/figures.hpp"
#include "../include/point2d.hpp"

TEST(RectangleTest, ConstructionFromStream) {
    std::stringstream ss("0, 0.0 4.0, 0 4.0, 3.0 0, 3.0");
    Rectangle<double> rectangle;
    ss >> rectangle;
    Point2d<double> center = rectangle.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 1.5);
}

TEST(RectangleTest, Center) {
    Rectangle<double> rectangle;
    rectangle.a = Point2d<double>(0, 0);
    rectangle.b = Point2d<double>(4, 0);
    rectangle.c = Point2d<double>(4, 3);
    rectangle.d = Point2d<double>(0, 3);
    Point2d<double> center = rectangle.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 1.5);
}

TEST(RectangleIntTest, Center) {
    Rectangle<int> rectangle;
    rectangle.a = Point2d<int>(0, 0);
    rectangle.b = Point2d<int>(4, 0);
    rectangle.c = Point2d<int>(4, 3);
    rectangle.d = Point2d<int>(0, 3);
    Point2d<int> center = rectangle.center();
    ASSERT_EQ(center.x(), 2);
    ASSERT_EQ(center.y(), 1);
}



TEST(RectangleTest, Equality) {
    Rectangle<double> rect1;
    rect1.a.set(0.0, 0.0);
    rect1.b.set(4.0, 0.0);
    rect1.c.set(4.0, 3.0);
    rect1.d.set(0.0, 3.0);

    Rectangle<double> rect2;
    rect2.a.set(0.0, 0.0);
    rect2.b.set(4.0, 0.0);
    rect2.c.set(4.0, 3.0);
    rect2.d.set(0.0, 3.0);

    ASSERT_TRUE(rect1 == rect2);
}

TEST(RectangleTest, Area) {
    Rectangle<double> rectangle;
    rectangle.a = Point2d<double>(0, 0);
    rectangle.b = Point2d<double>(4, 0);
    rectangle.c = Point2d<double>(4, 3);
    rectangle.d = Point2d<double>(0, 3);
    ASSERT_DOUBLE_EQ(double(rectangle), 12.0);
}



TEST(TrapezoidTest, ConstructionFromStream) {
    std::stringstream ss("0, 0.0 4.0, 0 4.0, 3.0 0, 3.0");
    Trapezoid<double> tr;
    ss >> tr;
    Point2d<double> center = tr.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 1.5);
}


TEST(TrapezoidIntTest, Center){
    Trapezoid<int> tr;
    tr.a = Point2d<int>(5,6);    
    tr.b = Point2d<int>(10,6);
    tr.c = Point2d<int>(10,1);
    tr.d = Point2d<int>(1,1);
    Point2d<int> center = tr.center();
    ASSERT_EQ(center.x(),6);
    ASSERT_EQ(center.y(), 3);
}


TEST(TrapezoidTest, Equality) {
    Trapezoid<double> tr;
    tr.a.set(0.0, 0.0);
    tr.b.set(5.0, 0.0);
    tr.c.set(4.0, 6.0);
    tr.d.set(0.0, 3.0);

    Trapezoid<double> tr2;
    tr2.a.set(0.0, 0.0);
    tr2.b.set(5.0, 0.0);
    tr2.c.set(4.0, 6.0);
    tr2.d.set(0.0, 3.0);

    ASSERT_TRUE(tr == tr2);
}

TEST(TrapezoidTest, Area) {
    Trapezoid<double> tr;
    tr.a = Point2d<double>(5.0, 6.0);
    tr.b = Point2d<double>(10.0, 6.0);
    tr.c = Point2d<double>(10.0, 1.0);
    tr.d = Point2d<double>(1.0, 1.0);
    ASSERT_DOUBLE_EQ(double(tr), 35);
}

TEST(RhombTest, ConstructionFromStream) {
    std::stringstream ss("0, 0.0 4.0, 0 4.0, 3.0 0, 3.0");
    Rhomb<double> rh;
    ss >> rh;
    Point2d<double> center = rh.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 0.0);
}

TEST(RhombTest,Center){
    Rhomb<double> rh;
    rh.a = Point2d<double>(1.0,6.0);
    rh.b = Point2d<double>(4.0,10.0);
    rh.c = Point2d<double>(7.0,6.0);
    rh.d = Point2d<double>(4.0,2.0);
    Point2d<double> center = rh.center();
    ASSERT_DOUBLE_EQ(center.x(),2.5);
    ASSERT_DOUBLE_EQ(center.y(), 8);
}

TEST(RhombIntTest,Center){
    Rhomb<int> rh;
    rh.a = Point2d<int>(1,6);
    rh.b = Point2d<int>(4,10);
    rh.c = Point2d<int>(7,6);
    rh.d = Point2d<int>(4,2);
    Point2d<int> center = rh.center();
    ASSERT_DOUBLE_EQ(center.x(),2);
    ASSERT_DOUBLE_EQ(center.y(), 8);
}




TEST(RhombTest, Equality) {
    Rhomb<double> rh;
    rh.a.set(0.0, 0.0);
    rh.b.set(5.0, 0.0);
    rh.c.set(4.0, 6.0);
    rh.d.set(0.0, 3.0);

    Rhomb<double> rh2;
    rh2.a.set(0.0, 0.0);
    rh2.b.set(5.0, 0.0);
    rh2.c.set(4.0, 6.0);
    rh2.d.set(0.0, 3.0);

    ASSERT_TRUE(rh == rh2);
}
TEST(RhombTest,Area){
    Rhomb<double> rh;
    rh.a = Point2d<double>(1.0,6.0);
    rh.b = Point2d<double>(4.0,10.0);
    rh.c = Point2d<double>(7.0,6.0);
    rh.d = Point2d<double>(4.0,2.0);
    ASSERT_DOUBLE_EQ(double(rh),24);
    
}



