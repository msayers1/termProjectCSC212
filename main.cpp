//main.cpp:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
#include "trie.h"

void loadDictionary(Trie* TrieTree);

int main(int argc, char* argv[]){
    Trie *TrieTree = new Trie();

    std::string input;
    
    bool running = true;
    bool result = false;
 
    while(running == true){
        std::cout << "\nThis Program will take an input of a word." << std::endl;
        std::cout << "Then look it up in the Scrabble Dictionary." << std::endl;
        std::cout << "If the word is in the dictionary, then it will return True." << std::endl;
        std::cout << "Otherwise it will return False." << std::endl;
        std::cout << "What word would you like to try:";
        std::cin >> input;
        result = TrieTree->search(input);
        if(result){
            std::cout << "\nYour word is a Scrabble word.";
            
        } else {
            std::cout << "\nYour word is not a Scrabble word.";
        }
    }
}
