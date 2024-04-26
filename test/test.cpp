#include <vector>

// #include "../include/Triangle.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
// using shapes::Triangle;

#include "../include/Awards.h"
using awards::AwardCeremonyActions;
using awards::RankList;
using ::testing::AtLeast;

class RankListStub : public RankList {
 private:
  std::vector<std::string> names;
  int currNameIndex;
 public:
  RankListStub() : currNameIndex(0) { 
    for (int i = 0; i < 10; i++) {
      names.push_back(std::to_string(i + 42));
      // names.push_back("This is a name.");
    } 
  };
  std::string getNext() override {
    if (currNameIndex < (int)names.size()) {
      return names[currNameIndex++];
    }
  }
  std::vector<std::string> getNames() { return names; }
};

// Test MockRankList
// TEST(AwardsTesting, GetNextTest) {
//   MockRankList* ranklist = new MockRankList();
//   EXPECT_EQ(ranklist->getNext(), "AAA");
// }

class MockAwardCeremonyActions : public AwardCeremonyActions {
 public:
  MOCK_METHOD(void, playAnthem, (), (override));
  MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
  MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
  MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
  MOCK_METHOD(void, awardGold, (std::string recipient), (override));
  
  // void playAnthem() {
  //   std::cout << "Playing the anthem" << std::endl;
  // }
  // void turnOffTheLightsAndGoHome() {
  //   std::cout << "Turning off the lights and going home" << std::endl;
  // }
  // void awardBronze(std::string recipient) {
  //   std::cout << "Awarding bronze medal to " << recipient << std::endl;
  // }
  // void awardSilver(std::string recipient) {
  //   std::cout << "Awarding silver medal to " << recipient << std::endl;
  // }
  // void awardGold(std::string recipient) {
  //   std::cout << "Awarding gold medal to " << recipient << std::endl;
  // }
};

// Test MockAwardCeremonyActions
TEST(AwardsTests, performAwardCeremonyTest) {
  RankListStub ranklist;
  MockAwardCeremonyActions awardCeremonyActions;

  EXPECT_CALL(awardCeremonyActions, playAnthem()).Times(AtLeast(1));
  EXPECT_CALL(awardCeremonyActions, awardBronze(ranklist.getNext())).Times(AtLeast(1));
  EXPECT_CALL(awardCeremonyActions, awardSilver(ranklist.getNext())).Times(AtLeast(1));
  EXPECT_CALL(awardCeremonyActions, awardGold(ranklist.getNext())).Times(AtLeast(1));
  EXPECT_CALL(awardCeremonyActions, turnOffTheLightsAndGoHome()).Times(AtLeast(1));

  performAwardCeremony(ranklist, awardCeremonyActions);

  // MockRankList ranklist;
  // MockAwardCeremonyActions actions;
  // std::stringstream buffer;
  // std::streambuf* oldCoutStreamBuf = std::cout.rdbuf(buffer.rdbuf());
  // awards::performAwardCeremony(ranklist, actions);
  // std::cout.rdbuf(oldCoutStreamBuf);
  // std::string expected_output = "Playing the anthem\nAwarding bronze medal to AAA\nAwarding silver medal to AAA\nAwarding gold medal to AAA\nTurning off the lights and going home\n";
  // EXPECT_EQ(buffer.str(), expected_output);
}
