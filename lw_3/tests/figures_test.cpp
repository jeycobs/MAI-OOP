#include <fstream>
#include <gtest/gtest.h>
#include "../include/figures.hpp"
#include "../include/point2d.hpp" 
TEST(RectangleTest, ConstructionFromStream) {
    std::stringstream ss("0, 0.0 4.0, 0 4.0, 3.0 0, 3.0");
    Rectangle rectangle;
    ss >> rectangle;
    Point2d center = rectangle.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 1.5);
}

TEST(RectangleTest, Center) {
    Rectangle rectangle;
    rectangle.a = Point2d(0, 0);
    rectangle.b = Point2d(4, 0);
    rectangle.c = Point2d(4, 3);
    rectangle.d = Point2d(0, 3);
    Point2d center = rectangle.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 1.5);
}

TEST(RectangleTest, Equality) {
    Rectangle rect1;
    rect1.a.set(0.0, 0.0);
    rect1.b.set(4.0, 0.0);
    rect1.c.set(4.0, 3.0);
    rect1.d.set(0.0, 3.0);

    Rectangle rect2;
    rect2.a.set(0.0, 0.0);
    rect2.b.set(4.0, 0.0);
    rect2.c.set(4.0, 3.0);
    rect2.d.set(0.0, 3.0);

    ASSERT_TRUE(rect1 == rect2);
}

TEST(RectangleTest, Area) {
    Rectangle rectangle;
    rectangle.a = Point2d(0, 0);
    rectangle.b = Point2d(4, 0);
    rectangle.c = Point2d(4, 3);
    rectangle.d = Point2d(0, 3);
    ASSERT_DOUBLE_EQ(double(rectangle), 12.0);
}

TEST(TrapezoidTest, ConstructionFromStream) {
    std::stringstream ss("0, 0.0 4.0, 0 4.0, 3.0 0, 3.0");
    Trapezoid tr;
    ss >> tr;
    Point2d center = tr.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 1.5);
}

TEST(TrapezoidTest, Center){
    Trapezoid tr;
    tr.a = Point2d(5,6);    
    tr.b = Point2d(10,6);
    tr.c = Point2d(10,1);
    tr.d = Point2d(1,1);
    Point2d center = tr.center();
    ASSERT_DOUBLE_EQ(center.x(),6.5);
    ASSERT_DOUBLE_EQ(center.y(), 3.5);
}


TEST(TrapezoidTest, Equality) {
    Trapezoid tr;
    tr.a.set(0.0, 0.0);
    tr.b.set(5.0, 0.0);
    tr.c.set(4.0, 6.0);
    tr.d.set(0.0, 3.0);

    Trapezoid tr2;
    tr2.a.set(0.0, 0.0);
    tr2.b.set(5.0, 0.0);
    tr2.c.set(4.0, 6.0);
    tr2.d.set(0.0, 3.0);

    ASSERT_TRUE(tr == tr2);
}

TEST(TrapezoidTest, Area) {
    Trapezoid tr;
    tr.a = Point2d(5, 6);
    tr.b = Point2d(10, 6);
    tr.c = Point2d(10, 1);
    tr.d = Point2d(1, 1);
    ASSERT_DOUBLE_EQ(double(tr), 35);
}


TEST(RhombTest, ConstructionFromStream) {
    std::stringstream ss("0, 0.0 4.0, 0 4.0, 3.0 0, 3.0");
    Rhomb rh;
    ss >> rh;
    Point2d center = rh.center();
    ASSERT_DOUBLE_EQ(center.x(), 2.0);
    ASSERT_DOUBLE_EQ(center.y(), 0.0);
}

TEST(RhombTest,Center){
    Rhomb rh;
    rh.a = Point2d(1,6);
    rh.b = Point2d(4,10);
    rh.c = Point2d(7,6);
    rh.d = Point2d(4,2);
    Point2d center = rh.center();
    ASSERT_DOUBLE_EQ(center.x(),2.5);
    ASSERT_DOUBLE_EQ(center.y(), 8);
}

TEST(RhombTest, Equality) {
    Rhomb rh;
    rh.a.set(0.0, 0.0);
    rh.b.set(5.0, 0.0);
    rh.c.set(4.0, 6.0);
    rh.d.set(0.0, 3.0);

    Rhomb rh2;
    rh2.a.set(0.0, 0.0);
    rh2.b.set(5.0, 0.0);
    rh2.c.set(4.0, 6.0);
    rh2.d.set(0.0, 3.0);

    ASSERT_TRUE(rh == rh2);
}
TEST(RhombTest,Area){
    Rhomb rh;
    rh.a = Point2d(1,6);
    rh.b = Point2d(4,10);
    rh.c = Point2d(7,6);
    rh.d = Point2d(4,2);
    ASSERT_DOUBLE_EQ(double(rh),24);
    
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}