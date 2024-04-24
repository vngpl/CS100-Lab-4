#include "gtest/gtest.h"
#include "../include/Triangle.h"
#include "../include/Awards.h"
#include <vector>
using shapes::Triangle;


TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

class MockRankList : public RankList {
public:
    std::string getNext() {
        return "AAA";
    }
};