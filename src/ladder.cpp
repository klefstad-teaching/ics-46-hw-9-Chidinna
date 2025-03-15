#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cerr << "Error found with " << word1 + word2 << " " << msg <<std::endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    //what does this  mean 😢
}

bool is_adjacent(const string& word1, const string& word2){
    int lenOne = word1.length();
    int SimCounter = 0;
    for (int i = 0; i < lenOne; ++i){
        if (word1[i] != word2[i]) SimCounter++;
    }
    return SimCounter == 1;
    // :OOOOO
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    /*function generate_word_ladder(begin_word, end_word, word_list):

    ladder_queue = queue of vector of strings
    std::queue<std::vector<string>> ladder_queue;

    ladder_queue.push([begin_word])

    visited = set of strings
    std::set<string> visited;

    visited.insert(begin_word)

    while (!ladder_queue.empty()){ is not empty:

        ladder = ladder_queue.pop_front()

        last_word = last element of ladder

        for word in word_list:

            if is_adjacent(last_word, word):

                if word not in visited:

                    visited.insert(word)

                    new_ladder = copy of ladder

                    new_ladder.push_back(word)

                    if word equals end_word:

                        return new_ladder

                    ladder_queue.push(new_ladder)
    }

    return no ladder found

end function*/
}

void load_words(set<string> & word_list, const string& file_name);

void print_word_ladder(const vector<string>& ladder);

void verify_word_ladder();