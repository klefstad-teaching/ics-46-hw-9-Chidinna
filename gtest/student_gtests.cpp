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

TEST(dijkstras, testInitialization) {
  
  Graph G;
  EXPECT_EQ(G.numVertices,0);
  G.numVertices = 4;
  G.resize(G.numVertices);
  G[0].push_back(Edge(0,1,3));
  G[1].push_back(Edge(1,2,5));
  G[2].push_back(Edge(2,3,4));
  EXPECT_EQ(G.numVertices, 4);
  //EXPECT_EQ(G)
}

TEST(dijkstras, fullTraversal) {
  
  Graph G;
  EXPECT_EQ(G.numVertices,0);
  G.numVertices = 4;
  G.resize(G.numVertices);
  G[0].push_back(Edge(0,1,3));
  G[1].push_back(Edge(1,2,5));
  G[2].push_back(Edge(2,3,4));
  EXPECT_EQ(G.numVertices, 4);
  int source = 0;
  int destination = 3;
  vector<int> previous;
  vector<int> distances = dijkstra_shortest_path(G, source, previous);
  vector<int> path = extract_shortest_path(distances, previous, destination);
  testing::internal::CaptureStdout();
  print_path(path, distances[destination]);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("0 1 2 3 \nTotal cost is 12\n", output);
  
  //EXPECT_EQ(G)
}

TEST(dijkstras, partTraversal) {
  
  Graph G;
  EXPECT_EQ(G.numVertices,0);
  G.numVertices = 4;
  G.resize(G.numVertices);
  G[0].push_back(Edge(0,1,3));
  G[1].push_back(Edge(1,2,5));
  G[2].push_back(Edge(2,3,4));
  EXPECT_EQ(G.numVertices, 4);
  int source = 2;
  int destination = 3;
  vector<int> previous;
  vector<int> distances = dijkstra_shortest_path(G, source, previous);
  vector<int> path = extract_shortest_path(distances, previous, destination);
  testing::internal::CaptureStdout();
  print_path(path, distances[destination]);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("2 3 \nTotal cost is 4\n", output);
  
  //EXPECT_EQ(G)
}

TEST(dijkstras, partialTraversal) {
  
  Graph G;
  EXPECT_EQ(G.numVertices,0);
  G.numVertices = 4;
  G.resize(G.numVertices);
  G[0].push_back(Edge(0,1,3));
  G[1].push_back(Edge(1,2,5));
  G[2].push_back(Edge(2,3,4));
  EXPECT_EQ(G.numVertices, 4);
  int source = 0;
  int destination = 2;
  vector<int> previous;
  vector<int> distances = dijkstra_shortest_path(G, source, previous);
  vector<int> path = extract_shortest_path(distances, previous, destination);
  testing::internal::CaptureStdout();
  print_path(path, distances[destination]);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ("0 1 2 \nTotal cost is 8\n", output);
  
  //EXPECT_EQ(G)
}