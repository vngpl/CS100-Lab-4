// <<<<<<< TriangleTestingBranch
#include "../include/Triangle.h"
#include "gtest/gtest.h"
#include <vector>

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
  
// <<<<<<< HailstoneTestingBranch
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
  
// <<<<<<< AwardTestingBranch
#include "gmock/gmock.h"
#include "../include/Awards.h"
  
using awards::AwardCeremonyActions;
using awards::RankList;
using ::testing::AtLeast;
using ::testing::InSequence;

class RankListStub : public RankList {
 private:
  std::vector<std::string> names = {"A", "B", "C"};
  int currNameIndex;
 public:
  RankListStub() : currNameIndex(0) { 
    for (int i = 0; i < 10; i++) {
      // names.push_back(std::to_string(i + 42));
      names.push_back("This is a name.");
    } 
  };
  std::string getNext() override {
    // if (currNameIndex < (int)names.size()) {
    //   return names[currNameIndex++];
    // }
    return "Name";
  }
  std::vector<std::string> getNames() { return names; }
};

class MockAwardCeremonyActions : public AwardCeremonyActions {
 public:
  MOCK_METHOD(void, playAnthem, (), (override));
  MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
  MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
  MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
  MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};

// Test MockAwardCeremonyActions
TEST(AwardsTests, performAwardCeremonyTest) {
  RankListStub ranklist;
  MockAwardCeremonyActions awardCeremonyActions;
  
  {
    InSequence seq;

    EXPECT_CALL(awardCeremonyActions, playAnthem()).Times(AtLeast(1));
    EXPECT_CALL(awardCeremonyActions, awardBronze(ranklist.getNext())).Times(AtLeast(1));
    EXPECT_CALL(awardCeremonyActions, awardSilver(ranklist.getNext())).Times(AtLeast(1));
    EXPECT_CALL(awardCeremonyActions, awardGold(ranklist.getNext())).Times(AtLeast(1));
    EXPECT_CALL(awardCeremonyActions, turnOffTheLightsAndGoHome()).Times(AtLeast(1));
  }

  performAwardCeremony(ranklist, awardCeremonyActions);
}