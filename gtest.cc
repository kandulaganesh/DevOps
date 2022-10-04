#include <gtest/gtest.h>

/*
    How to compile:
       g++ -Wall -g gtest.cc -lgtest_main  -lgtest -o gtest
       
     References:
       https://www.youtube.com/watch?v=16FI1-d2P4E&t=665s
*/


struct findSquare: testing::Test {
    int getSquare(int value){
        return value * value;
    }
};

int findSum(int a, int b){
    return a + b;
}

TEST_F(findSquare, positive) {
    ASSERT_EQ(36, getSquare(6.0));
}

TEST(calculateSum, addition){
    ASSERT_EQ(36, findSum(12,24));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
