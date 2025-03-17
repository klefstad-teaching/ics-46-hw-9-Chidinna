#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cerr << "Error found with " << word1 + word2 << " " << msg <<std::endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int lenOne = str1.length();
    int lenTwo = str2.length();
    if (abs(lenOne - lenTwo) > d) return false;
    int j = 0;
    int i = 0;
    int total = 0;
    while(i < lenOne && j < lenTwo){
        if(str1[i] == str2[j]){
            ++i;
            ++j;
        }else{
            if (lenOne == lenTwo){
                ++i;
                ++j;
            }else if(lenOne > lenTwo) ++i;
            else if (lenOne < lenTwo) ++j;
            ++total;
        }
        
    }
    //std::cout << d;
    return (total + abs(lenOne-i) + abs(lenTwo - j)) <= d;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
    // :OOOOO
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    //ladder_queue = queue of vector of strings
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();

        for (const string& word : word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);
                visited.insert(word);

                if (word == end_word) return new_ladder;

                ladder_queue.push(new_ladder);
            }
        }
    }
    return {};

//end function
}

void load_words(set<string> & word_list, const string& file_name){
    std::ifstream file(file_name);
    if (!file.is_open()){error("", "","File doesn't exist"); return;}
    std::string line;
    while (file >> line){
        //std::cout << line << std::endl;
        word_list.insert(line); 
    }
    file.close();
}

void print_word_ladder(const vector<string>& ladder){
    if (ladder.empty()){ std::cout << "No word ladder found." << std::endl; return;}
    std::cout << "Word ladder found: ";
    for (int i = 0 ; i < ladder.size(); ++i) std::cout << ladder[i] << " ";
    std::cout << std::endl;
}

void verify_word_ladder(){
    set<string> word_list;

    load_words(word_list, "src/words.txt");

    print_word_ladder(generate_word_ladder("cat", "dog", word_list));

    print_word_ladder(generate_word_ladder("marty", "curls", word_list));

    print_word_ladder(generate_word_ladder("code", "data", word_list));

    print_word_ladder(generate_word_ladder("work", "play", word_list));

    print_word_ladder(generate_word_ladder("sleep", "awake", word_list));

    print_word_ladder(generate_word_ladder("car", "cheat", word_list));
}