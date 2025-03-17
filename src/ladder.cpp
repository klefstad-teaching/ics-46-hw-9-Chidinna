#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cerr << "Error found with " << word1 + word2 << " " << msg <<std::endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    //what does this  mean 😢
    std::cout << d;
    return is_adjacent(str1, str2);
}

bool is_adjacent(const string& word1, const string& word2){
    int lenOne = word1.length();
    int lenTwo = word2.length();
    int SimCounter = 0;
    if (lenOne-lenTwo == 0){
        for (int i = 0; i < lenOne; ++i){
            if (word1[i] != word2[i]) SimCounter++;
        }
        return SimCounter == 1;
    }else if (((lenOne-lenTwo) == 1) || ((lenOne-lenTwo) == -1)){
        string longWord;
        string shortWord;
        if (lenOne > lenTwo){
             longWord = word1;
             shortWord = word2;

        }else {
             longWord = word2;
             shortWord = word1;
        }
        int i = 0; 
        int j = 0;
        bool diff;
        while(i < longWord.length() && j < shortWord.length()){
            if(longWord[i] != shortWord[j]){
                if (diff) return false;
                else{
                    diff = true; 
                    ++i;
                }
            }else{
                ++i;
                ++j;
            }
        }
        return true;
    }
    return false;
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
    for (int i = 0 ; i < ladder.size(); ++i)
    std::cout << ladder[i] << " ";
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