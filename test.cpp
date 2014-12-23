#include "test.h"
#include <gtest/gtest.h>

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
  char *s1, *s2;

  ASSERT_FALSE(anagram(s1, s2));
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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}