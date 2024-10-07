// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"


TEST(fizzbuzz_tests, fizz) {

    EXPECT_EQ(fizzbuzz(6), "Fizz");
}

TEST(fizzbuzz_tests, buzz) {

    EXPECT_EQ(fizzbuzz(10), "Buzz");
}

TEST(fizzbuzz_tests, fizzbuzz) {

    EXPECT_EQ(fizzbuzz(15), "FizzBuzz");
}

TEST(fizzbuzz_tests, nothing) {

    EXPECT_EQ(fizzbuzz(22), "");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

