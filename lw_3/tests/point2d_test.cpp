#include "gtest/gtest.h"
#include "../include/point2d.hpp"
TEST(Point2dTest, DefaultConstructor) {
    Point2d point;
    ASSERT_EQ(point.x(), 0.0);
    ASSERT_EQ(point.y(), 0.0);
}

TEST(Point2dTest, ParameterizedConstructor) {
    Point2d point(2.0, 3.0);
    ASSERT_EQ(point.x(), 2.0);
    ASSERT_EQ(point.y(), 3.0);
}

TEST(Point2dTest, SetXAndY) {
    Point2d point;
    point.x(4.0);
    point.y(5.0);
    ASSERT_EQ(point.x(), 4.0);
    ASSERT_EQ(point.y(), 5.0);
}

TEST(Point2dTest, DistanceTo) {
    Point2d point1(1.0, 2.0);
    Point2d point2(4.0, 6.0);
    ASSERT_DOUBLE_EQ(point1.distanceTo(point2), 5.0);
}

TEST(Point2dTest, DotProduct) {
    Point2d point1(2.0, 3.0);
    Point2d point2(4.0, 5.0);
    ASSERT_DOUBLE_EQ(point1.dotProduct(point2), 23.0);
}

TEST(Point2dTest, Equality) {
    Point2d point1(2.0, 3.0);
    Point2d point2(2.0, 3.0);
    Point2d point3(4.0, 5.0);
    ASSERT_TRUE(point1 == point2);
    ASSERT_FALSE(point1 == point3);
}

TEST(Point2dTest, AssignmentOperator) {
    Point2d point1(2.0, 3.0);
    Point2d point2(4.0, 5.0);
    point2 = point1;
    ASSERT_EQ(point2.x(), 2.0);
    ASSERT_EQ(point2.y(), 3.0);
}

TEST(Point2dTest, AdditionOperator) {
    Point2d point1(2.0, 3.0);
    Point2d point2(4.0, 5.0);
    Point2d result = point1 + point2;
    ASSERT_EQ(result.x(), 6.0);
    ASSERT_EQ(result.y(), 8.0);
}

TEST(Point2dTest, SubtractionOperator) {
    Point2d point1(4.0, 5.0);
    Point2d point2(2.0, 3.0);
    Point2d result = point1 - point2;
    ASSERT_EQ(result.x(), 2.0);
    ASSERT_EQ(result.y(), 2.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}