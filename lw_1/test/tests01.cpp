#include <gtest/gtest.h>
#include "../include/validbrackets.h"

TEST(test_01, basic_test_get){
    ASSERT_TRUE(validBrackets("()") == true);
}

TEST(test_02, basic_test_get){
    ASSERT_TRUE(validBrackets(")(()))") == false);
}

TEST(test_03, basic_test_get){
    ASSERT_TRUE(validBrackets("(") == false);
}

TEST(test_04, basic_test_get){
    ASSERT_TRUE(validBrackets("(())((()())())") == true);
}

TEST(test_05, basic_test_get){
    ASSERT_TRUE(validBrackets("()()()") == true);
}

TEST(test_06, basic_test_get){
    ASSERT_TRUE(validBrackets("(((") == false);
}

TEST(test_07, basic_test_get){
    ASSERT_TRUE(validBrackets("(()())(") == false);
}

TEST(test_08, basic_test_get){
    ASSERT_TRUE(validBrackets("") == true);
}
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
