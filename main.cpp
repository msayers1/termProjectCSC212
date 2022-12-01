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
    Trie *TrieTree2 = new Trie();
    Trie *TrieTree3 = new Trie();
    Trie *TrieTree4 = new Trie();
    Trie *TrieTree5 = new Trie();
    Trie *TrieTree6 = new Trie();
    Trie *TrieTree7 = new Trie();
    Trie *TrieTree8 = new Trie();
    Trie *TrieTree9 = new Trie();
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
    // Initialize vectors for the time values. 
    std::vector<float> insertValue;
    std::vector<float> visualizeValue;
    std::vector<float> recursiveValue;
    //initialize the state and stop times. 
    unsigned long cStart , cEnd ;

    //Word: 33
    std::vector<std::string> wordList2;
    //Reads the file for the word list. 
    readFile("visualizationWordList.txt", &wordList2); 
    //Starts the clock for the insert function. 
    cStart = std::clock();
    for(int i = 0; i < wordList2.size(); i++){
        //std::cout << wordList[i] << std::endl;
        //runs the insert function. 
        TrieTree2->insert(wordList2[i]);
    }
    //Stops the clock for the insert function. 
    cEnd = std::clock();
    //intialize and multiplies the difference of the start and stop, divides by clocks per second. 
    float time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    //Pushes the time value on the insert vector. 
    insertValue.push_back(time);

    //Announces the ascend display.
    std::cout << "This is the ascend function output:" << std::endl;
    //runs the ascend function
    TrieTree2->ascend();
    //Puts a new line in for the next function.
    std::cout  << std::endl;

    //Announces the ascend display.
    std::cout << "This is the descend function output:" << std::endl;
    //runs the descend function. 
    TrieTree2->descend();
    //Puts a new line in for the next function.
    std::cout  << std::endl;

    //Starts the clock for the recursive insert function. 
    cStart = std::clock();
    for(int i = 0; i < wordList2.size(); i++){
        //std::cout << wordList[i] << std::endl;
        //runs the recursive insert function. 
        TrieTree3->recursiveInsert(wordList2[i]);
    }
    //Stops the clock for the insert function.
    cEnd = std::clock();
    //intialize and multiplies the difference of the start and stop, divides by clocks per second. 
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    //Pushes the time value on the recursive insert vector. 
    recursiveValue.push_back(time);

    //Starts the clock for the visualization function. 
    cStart = std::clock();
    //runs the visualization insert function. 
    TrieTree2->visualize("graph_Visualization.dot");
    //Stops the clock for the visualization function.
    cEnd = std::clock();
    //intialize and multiplies the difference of the start and stop, divides by clocks per second. 
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    //Pushes the time value on the visualization vector. 
    visualizeValue.push_back(time);

    //Words: 12972
    std::vector<std::string> wordList3;
    //Reads the file for the word list. 
    readFile("wordledictionarylist.txt", &wordList3); 
    cStart = std::clock();
    for(int i = 0; i < wordList3.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree4->insert(wordList3[i]);
    }
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    insertValue.push_back(time);

    cStart = std::clock();
    for(int i = 0; i < wordList3.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree5->recursiveInsert(wordList3[i]);
    }
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    recursiveValue.push_back(time);

    cStart = std::clock();
    TrieTree4->visualize("graph_wordle.dot");
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    visualizeValue.push_back(time);
    // Visualization Graph is too large.
    // TrieTree4->visualize("graph_wordle.dot");

    //Words: 222050
    std::vector<std::string> wordList4;
    readFile("MobeyDick.txt", &wordList4); 
    cStart = std::clock();
    for(int i = 0; i < wordList4.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree6->insert(wordList4[i]);
    }
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    insertValue.push_back(time);

    cStart = std::clock();
    for(int i = 0; i < wordList4.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree7->recursiveInsert(wordList4[i]);
    }
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    recursiveValue.push_back(time);

    cStart = std::clock();
    TrieTree6->visualize("graph_MobeyDick.dot");
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    visualizeValue.push_back(time);
    // Visualization Graph is too large.
    // TrieTree3->visualize("graph_MobeyDick.dot");

    //Words: 515572
    std::vector<std::string> wordList5;
    readFile("dictionary.txt", &wordList5); 
    cStart = std::clock();
    for(int i = 0; i < wordList5.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree8->insert(wordList5[i]);
    }
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    insertValue.push_back(time);

    cStart = std::clock();
    for(int i = 0; i < wordList5.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree9->recursiveInsert(wordList5[i]);
    }
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    recursiveValue.push_back(time);

    cStart = std::clock();
    TrieTree8->visualize("graph_dictionary.dot");
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    visualizeValue.push_back(time);
    // Visualization Graph is too large.
    // TrieTree4->visualize("graph_dictionary.dot");

    TrieTree8->destroy();
    cStart = std::clock();
    TrieTree8->visualize("graph_dictionary_empty.dot");
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    visualizeValue.push_back(time);

    for(int i = 0; i < insertValue.size(); i++){
        std::cout << " Insert timing: " << insertValue[i] << std::endl;
    }
    for(int i = 0; i < recursiveValue.size(); i++){
        std::cout << " Recursive Insert timing: " << recursiveValue[i] << std::endl;
    }
    for(int i = 0; i < visualizeValue.size(); i++){
        std::cout << " Visualize timing: " << visualizeValue[i] << std::endl;
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
 
