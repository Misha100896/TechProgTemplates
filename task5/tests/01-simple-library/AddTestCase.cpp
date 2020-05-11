//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTest, Equal) {
    ASSERT_EQ(Add(2, 2), 4);
}

TEST(IsLeapTest, InvalidArg) {
    ASSERT_THROW(IsLeap(-100), std::invalid_argument);
}

TEST(IsLeapTest, LeapYears) {
    ASSERT_TRUE(IsLeap(2020));
    ASSERT_TRUE(IsLeap(2000));
}

TEST(IsLeapTest, NotLeapYears) {
    ASSERT_FALSE(IsLeap(2001));
    ASSERT_FALSE(IsLeap(1900));
}