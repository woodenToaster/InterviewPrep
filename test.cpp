#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include "test.h"
#include <vector>

/*******************/
/** anagram tests **/
/*******************/

TEST(anagramTest, isAnagram) {
	char *s1 = "torchwood";
  char *s2 = "doctorwho";
  char *s3 = "weird";
  char *s4 = "wired";
  char *s5 = "a";
  char *s6 = "a";

  ASSERT_TRUE(anagram(s1, s2));
  ASSERT_TRUE(anagram(s3, s4));
  ASSERT_TRUE(anagram(s5, s6));
}

TEST(anagramTest, noArgs) {
  char *s1 = nullptr;
  char *s2 = nullptr;
  ASSERT_THROW(anagram(s1, s2), std::invalid_argument);
  s1 = "1arg";
  ASSERT_THROW(anagram(s1, s2), std::invalid_argument);
}

TEST(anagramTest, notAnagram) {
  char *s1 = "abcd";
  char *s2 = "wxyz";
  char *s3 = "abcd";
  char *s4 = "abcc";
  char *s5 = "abcd";
  char *s6 = "bbcd";
  char *s7 = "abc";
  char *s8 = "abcd";
  char *s9 = "word";
  char *s10 = "lord";

  ASSERT_FALSE(anagram(s1, s2));
  ASSERT_FALSE(anagram(s3, s4));
  ASSERT_FALSE(anagram(s5, s6));
  ASSERT_FALSE(anagram(s7, s8));
  ASSERT_FALSE(anagram(s9, s10));
}

/************************/
/** rotate image tests **/
/************************/

TEST(rotate90, baseCase) {
  int **matrix;
  matrix[0] = new int[1];
  matrix[0][0] = 25;
  rotate90(matrix, 1);
  int expected[1][1] = {{25}};
  for(int i = 0; i < 1; i++) {
    for(int j = 0; j < 1; j++) {
      ASSERT_EQ(expected[i][j], matrix[i][j]);
    }
  }
  delete[] matrix[0];
}

//TEST(rotate90, validRotation) {
//  int **matrix;
//  matrix[0] = new int[3]{0, 0, 24};
//  matrix[1] = new int[3]{0, 25, 0};
//  matrix[2] = new int[3]{0, 1, 0};
//
//  int expected[3][3] = {
//    {0, 0, 0},
//    {1, 25, 0},
//    {0, 0, 24}
//  };
//
//  rotate90(matrix, 3);
//
//  int i, j;
//  for(i = 0; i < 3; i++) {
//    for(j = 0; j < 3; j++) {
//      ASSERT_EQ(expected[i][j], matrix[i][j]);
//    }
//  }
//  delete[] matrix[0];
//  delete[] matrix[1];
//  delete[] matrix[2];
//}

//**********************//
//** Binary code test **//
//**********************//

TEST(decode, validEncoding) {
  std::vector<std::string> vec = decode("123210122");
  ASSERT_EQ(vec[0], "011100011");
  ASSERT_EQ(vec[1], "NONE");
}

//********************//
//** getProfit test **//
//********************//

TEST(getProfit, testMax) {
  std::vector<int> vec1 = {3, 5, 10, 20, 80, 70, 40, 1};
  std::vector<int> vec2 = {80, 70, 40, 3, 2, 1};
  ASSERT_EQ(77, getProfit(vec1));
  ASSERT_EQ(0, getProfit(vec2));
}

TEST(getProfit, testEmptyVector) {
  std::vector<int> vec = {};
  std::vector<int> vec1 = {50};
  ASSERT_EQ(0, getProfit(vec));
  ASSERT_EQ(0, getProfit(vec1));
}

/**********/
/** main **/
/**********/

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
