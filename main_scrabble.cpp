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

void readFile(std::string filename, std::vector<std::string>*wordList);

int main(int argc, char* argv[]){
    //Initializes the Trie trees for the different word list and insert function combinations. 
    Trie *TrieTree = new Trie();

    //initializes the input. 
    std::string input;
    std::vector<std::string> wordList;
    readFile("scrabbleWords.txt", &wordList); 
    for(int i = 0; i < wordList.size(); i++){
        //inserts the word list for the Scrabble word check. 
        TrieTree->insert(wordList[i]);
    }
    
  bool running = true;
    bool result = false;
    
    while(running == true){
        std::cout << "\nThis Program will take an input of a word." << std::endl;
        std::cout << "Then look it up in the Scrabble Dictionary." << std::endl;
        std::cout << "If the word is in the dictionary, then it will state that the word is a scrabble word." << std::endl;
        std::cout << "Otherwise it will state that the word is not a scrabble word." << std::endl;
        std::cout << "What word would you like to try:";
        std::cin >> input;
        std::cout << input << std::endl;
        if(input == "quit"){
            running = false; 
        }else{
            result = TrieTree->search(input);
            if(result > 0){
                std::cout << "\nYour word is a Scrabble word.";
                
            } else {
                std::cout << "\nYour word is not a Scrabble word.";
            }
        }
        
    }
    
}


void readFile(std::string filename, std::vector<std::string>*wordList){
        // Opens the file for reading
        std::ifstream file(filename);
        // Creates a string to hold each line in temporarily
        std::string str;
        // Creates a string to hold each line in temporarily
        std::string wordTemp;

        // Iterates over the file, storing one line at a time into `str`
        while (getline(file, str)) {
            // Create a stringstream object with each line from the file
            std::istringstream ss(str); 
            //Grabs the values from the line. 
            while(ss >> wordTemp){
                //Places the word on the vector.
                (*wordList).push_back(wordTemp);
            }
            
        }
   }
 
