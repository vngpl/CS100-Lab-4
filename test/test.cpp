#include <vector>

// #include "../include/Triangle.h"
#include "gtest/gtest.h"
// using shapes::Triangle;

#include "../include/Awards.h"
using awards::AwardCeremonyActions;
using awards::RankList;

class MockRankList : public RankList {
 public:
  std::string getNext() { return "AAA"; }
};

// Test MockRankList
// TEST(AwardsTesting, GetNextTest) {
//   MockRankList* ranklist = new MockRankList();
//   EXPECT_EQ(ranklist->getNext(), "AAA");
// }

class MockAwardCeremonyActions : public AwardCeremonyActions {
 public:
  void playAnthem() {
    std::cout << "Playing the anthem" << std::endl;
  }
  void turnOffTheLightsAndGoHome() {
    std::cout << "Turning off the lights and going home" << std::endl;
  }
  void awardBronze(std::string recipient) {
    std::cout << "Awarding bronze medal to " << recipient << std::endl;
  }
  void awardSilver(std::string recipient) {
    std::cout << "Awarding silver medal to " << recipient << std::endl;
  }
  void awardGold(std::string recipient) {
    std::cout << "Awarding gold medal to " << recipient << std::endl;
  }
};

// Test MockAwardCeremonyActions
TEST(AwardsTests, performAwardCeremonyTest) {
  MockRankList ranklist;
  MockAwardCeremonyActions actions;
  awards::performAwardCeremony(ranklist, actions);
}
