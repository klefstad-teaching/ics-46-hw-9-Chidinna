#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(ladder, CattoRat) {
  
  set<string> word_list;

  load_words(word_list, "../src/words.txt");

  vector<string> e = generate_word_ladder("cat", "rat", word_list);
  EXPECT_EQ(e.size(), 2);
  testing::internal::CaptureStdout();
  print_word_ladder(e);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("Word ladder found: cat rat \n", output);
}
