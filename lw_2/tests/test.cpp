#include <gtest/gtest.h>
#include "../include/Octal.hpp"

TEST(test_plus, basic_test_set) {
    Octal x1("123");
    x1 += x1;
    ASSERT_TRUE(x1 == Octal("246"));

    Octal x2("10");
    x2 += Octal("12");
    ASSERT_TRUE(x2 == Octal("22"));

    Octal x3("6531232");
    ASSERT_TRUE((x3 + Octal("1000")) == Octal("6532232"));
}

TEST(test_minus, basic_test_set) {
    Octal x1("123");
    x1 -= Octal("23");
    ASSERT_TRUE(x1 == Octal("100"));

    Octal x2("7777");
    x2 -= Octal("3333");
    ASSERT_TRUE(x2 == Octal("4444"));

    Octal x3("6531232");
    ASSERT_TRUE((x3 - Octal("1000")) == Octal("6530232"));

}

TEST(test_greater, basic_test_set) {
    ASSERT_TRUE(Octal("123") > Octal("32"));

    ASSERT_TRUE(Octal("413620051") > Octal("352554"));

    ASSERT_FALSE(Octal("352554") > Octal("413620051"));
}

TEST(test_less, basic_test_set) {
    ASSERT_FALSE(Octal("123") < Octal("32"));

    ASSERT_FALSE(Octal("413620051") < Octal("352554"));

    ASSERT_TRUE(Octal("352554") < Octal("413620051"));
}

TEST(test_eq, basic_test_set) {
    ASSERT_TRUE(Octal("235234") == Octal("235234"));

    ASSERT_TRUE(Octal("0") == Octal("0"));

    ASSERT_FALSE(Octal("653242") == Octal("23421"));
}


TEST(test_not_eq, basic_test_set) {
    ASSERT_FALSE(Octal("235234") != Octal("235234"));

    ASSERT_FALSE(Octal("0") != Octal("0"));

    ASSERT_TRUE(Octal("653242") != Octal("23421"));
}

TEST(test_constructors, basic_test_set) {
    Octal x1("123");
    Octal x2(x1);
    x2 -= Octal("3");

    ASSERT_TRUE(x2 == (x1 - Octal("3")));

    Octal x3("5432");
    Octal x4 = x3;
    x4 += Octal("1");

    ASSERT_TRUE(x4 == Octal("5433"));

    Octal x5({'5'});
    ASSERT_TRUE(x5 == Octal("5"));
}





