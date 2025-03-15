#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cerr << "Error found with " << word1 + word2 << " " << msg <<std::endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    //what does this  mean 😢
}

bool is_adjacent(const string& word1, const string& word2){
    int lenOne = word1.length();
    int lenTwo = word2.length();
    int SimCounter = 0;
    if (lenOne-lenTwo = 0){
        for (int i = 0; i < lenOne; ++i){
            if (word1[i] != word2[i]) SimCounter++;
        }
        return SimCounter == 1;
    }else if (lenOne-lenTwo == 1){
        for (int i = 0; i < lenOne; ++i){
            if (word1[i] != word2[i]) SimCounter++;
        }
        return SimCounter == 1;
    }else if (lenOne-lenTwo == -1){ //only allowed to have a one difference

    }
    return false
    // :OOOOO
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    //ladder_queue = queue of vector of strings
    std::queue<std::vector<string>> ladder_queue;

    ladder_queue.push([begin_word]);

    //visited = set of strings
    std::set<string> visited;

    visited.insert(begin_word);

    while (!ladder_queue.empty()){ is not empty:

        ladder = ladder_queue.pop();

       // last_word = last element of ladder
        last_word = ladder[ladder.size()-1];

        //for word in word_list:
        for(string word : ladder){

            if is_adjacent(last_word, word){

                if (!visited.find(word) != visited.end()){//word not in visited:

                    visited.insert(word)

                    //new_ladder = copy of ladder
                    std::set<string> new_ladder = ladder; 

                    new_ladder.push_back(word);

                    if(word == end_word) return new_ladder;

                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return ladder;

//end function
}

void load_words(set<string> & word_list, const string& file_name);

void print_word_ladder(const vector<string>& ladder){
    for (int i = 0 ; i < ladder.size(); ++i)
    std::cout << ladder[i] << " ";
}

void verify_word_ladder();