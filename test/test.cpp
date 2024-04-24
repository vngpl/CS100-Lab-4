#include "../include/Triangle.h"
#include "gtest/gtest.h"
using shapes::Triangle;

// TEST(TriangleTests, testPerimeter) {
//   Triangle *aTriangle = new Triangle(3, 3, 3);
//   EXPECT_EQ(aTriangle->getPerimeter(), 9);
// }

TEST(TriangleTests, testPerimeter) {
  Triangle *aTriangle = new Triangle(3, 2, 3);
  EXPECT_EQ(aTriangle->getPerimeter(), 8);
}

TEST(TriangleTests, testArea) {
  Triangle *aTriangle = new Triangle(5, 4, 3);
  EXPECT_EQ(aTriangle->getArea(), 6);
}

TEST(TriangleTests, testKind) {
  Triangle *aTriangle = new Triangle(3, 3, 3);
  EXPECT_EQ(aTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}
