#include <iostream>
#include <string>
#include <map>

bool anagramm(std::map<std::string, int>* w1,std::map<std::string, int>* w2) {
    int count=0;
    for (std::map<std::string, int>::iterator iti=w2->begin(); iti!=w2->end();++iti) {
        for (std::map<std::string, int>::iterator itj=w1->begin(); itj!=w1->end();++itj) {
            if (iti->first==itj->first) {
                count++;
            }
        }
    }
    if (count==w2->size()) {
        return true;
    }
    else
        return false;
}

int main() {
    std::cout << "Enter words: ";
    std::string word1, word2;
    std::cin>>word1>>word2;

    std::map<std::string, int> w1;
    std::map<std::string, int> w2;

    if (word1.length()>word2.length()) {
        for (int i = 0; i < word1.length(); ++i) {
            std::pair<std::string, int> w1Pair(word1.substr(i, 1), i);
            w1.insert(w1Pair);
        }
        for (int i = 0; i < word2.length(); ++i) {
            std::pair<std::string, int> w2Pair(word2.substr(i, 1), i);
            w2.insert(w2Pair);
        }
    }
    else {
        for (int i = 0; i < word1.length(); ++i) {
            std::pair<std::string, int> w1Pair(word1.substr(i, 1), i);
            w2.insert(w1Pair);
        }
        for (int i = 0; i < word2.length(); ++i) {
            std::pair<std::string, int> w2Pair(word2.substr(i, 1), i);
            w1.insert(w2Pair);
        }
    }

    std::cout<<anagramm(&w1,&w2);
}
