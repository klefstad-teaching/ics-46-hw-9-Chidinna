#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(ladder, CattoExistent) {
  
  set<string> word_list;

  load_words(word_list, "../src/words.txt");

  vector<string> e = generate_word_ladder("cat", "rat", word_list);
  EXPECT_EQ(e.size(), 2);
  testing::internal::CaptureStdout();
  print_word_ladder(e);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("Word ladder found: cat rat \n", output);
}

TEST(ladder, wordToNonexistent) {
  
  set<string> word_list;

  load_words(word_list, "../src/words.txt");

  vector<string> e = generate_word_ladder("cat", "zat", word_list);
  EXPECT_EQ(e.size(), 0);
  testing::internal::CaptureStdout();
  print_word_ladder(e);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("No word ladder found.\n", output);
  EXPECT_TRUE(is_adjacent("cat", "zat"));
}

TEST(ladder, NonexistentwordToexistent) {
  
  set<string> word_list;

  load_words(word_list, "../src/words.txt");

  vector<string> e = generate_word_ladder("zat", "bat", word_list);
  EXPECT_EQ(e.size(), 2);
  testing::internal::CaptureStdout();
  print_word_ladder(e);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("Word ladder found: zat bat \n", output);
  EXPECT_TRUE(is_adjacent("zat", "bat"));
}

TEST(ladder, wordtoitself) {
  
  set<string> word_list;

  load_words(word_list, "../src/words.txt");

  vector<string> e = generate_word_ladder("bat", "bat", word_list);
  EXPECT_EQ(e.size(), 0);
  testing::internal::CaptureStdout();
  print_word_ladder(e);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("No word ladder found.\n", output);
  EXPECT_TRUE(is_adjacent("bat", "bat"));
}

TEST(ladder, blankToExistent) {
  
  set<string> word_list;

  load_words(word_list, "../src/words.txt");

  vector<string> e = generate_word_ladder(" ", "bat", word_list);
  EXPECT_EQ(e.size(), 0);
  testing::internal::CaptureStdout();
  print_word_ladder(e);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("No word ladder found.\n", output);
  EXPECT_FALSE(is_adjacent(" ", "bat"));
}