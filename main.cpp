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
    // Trie *TrieTree = new Trie();
    // Trie *TrieTree2 = new Trie();
    Trie *TrieTree3 = new Trie();

    // std::string input;
    // std::vector<std::string> wordList;
    // readFile("scrabbleWords.txt", &wordList); 
    // for(int i = 0; i < wordList.size(); i++){
    //     //std::cout << wordList[i] << std::endl;
    //     TrieTree->insert(wordList[i]);
    // }
    

    // std::vector<std::string> wordList2;
    // readFile("visualizationWordList.txt", &wordList2); 
    // for(int i = 0; i < wordList2.size(); i++){
    //     //std::cout << wordList[i] << std::endl;
    //     TrieTree2->insert(wordList2[i]);
    // }
    
    // TrieTree2->visualize("graph1.dot");
    // bool running = true;
    // bool result = false;
    
    std::vector<std::string> wordList3;
    readFile("visualizationWordList.txt", &wordList3); 
    for(int i = 0; i < wordList3.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree3->recursiveInsert(wordList3[i]);
    }
    
    TrieTree3->visualize("graph_recursive.dot");

    // while(running == true){
    //     std::cout << "\nThis Program will take an input of a word." << std::endl;
    //     std::cout << "Then look it up in the Scrabble Dictionary." << std::endl;
    //     std::cout << "If the word is in the dictionary, then it will return True." << std::endl;
    //     std::cout << "Otherwise it will return False." << std::endl;
    //     std::cout << "What word would you like to try:";
    //     std::cin >> input;
    //     result = TrieTree->search(input);
    //     if(result){
    //         std::cout << "\nYour word is a Scrabble word.";
            
    //     } else {
    //         std::cout << "\nYour word is not a Scrabble word.";
    //     }
    // }
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