#include "gtest/gtest.h"

#include "../include/Hailstone.h"

using sequence::satisfiesHailstone;


TEST(HailstoneTests, testZero) {
  EXPECT_FALSE(sequence::satisfiesHailstone(0));
}

TEST(HailstoneTests, testOne) {
  EXPECT_TRUE(sequence::satisfiesHailstone(1));
}

TEST(HailstoneTests, testEven) {
  EXPECT_TRUE(sequence::satisfiesHailstone(4));
}

TEST(HailstoneTests, testOthers) {
  EXPECT_TRUE(sequence::satisfiesHailstone(19937));
}
