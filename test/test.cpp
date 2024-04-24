#include "../include/Triangle.h"
#include "gtest/gtest.h"
using shapes::Triangle;

// TEST(TriangleTests, testPerimeter) {
//   Triangle *aTriangle = new Triangle(3, 3, 3);
//   EXPECT_EQ(aTriangle->getPerimeter(), 9);
// }

// 3 tests to check perimeter, area, and kind
TEST(TriangleTests, testPerimeter) {
  Triangle *aTriangle = new Triangle(3, 2, 3);
  EXPECT_EQ(aTriangle->getPerimeter(), 8);
}

TEST(TriangleTests, testArea) {
  Triangle *aTriangle = new Triangle(5, 4, 3);
  EXPECT_DOUBLE_EQ(aTriangle->getArea(), 6.0);
}

TEST(TriangleTests, testKindEquilateral) {
  Triangle *aTriangle = new Triangle(3, 3, 3);
  EXPECT_EQ(aTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}

// 1 test to check death
TEST(TriangleTests, testDeath) {
  EXPECT_DEATH({Triangle tri(1, 1, 2);}, "invalid triangle");
}

// 3 additional tests
TEST(TriangleTests, testNoThrow) {
  EXPECT_NO_THROW({Triangle tri(5, 4, 3);});
}

TEST(TriangleTests, testKindIsosceles) {
  Triangle *aTriangle = new Triangle(3, 3, 2);
  EXPECT_EQ(aTriangle->getKind(), Triangle::Kind::ISOSCELES);
}

TEST(TriangleTests, testKindScalene) {
  Triangle *aTriangle = new Triangle(5, 4, 3);
  EXPECT_EQ(aTriangle->getKind(), Triangle::Kind::SCALENE);
}