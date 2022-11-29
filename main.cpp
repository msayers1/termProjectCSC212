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
    Trie *TrieTree = new Trie();
    Trie *TrieTree2 = new Trie();
    Trie *TrieTree3 = new Trie();
    Trie *TrieTree4 = new Trie();
    Trie *TrieTree5 = new Trie();
    Trie *TrieTree6 = new Trie();
    Trie *TrieTree7 = new Trie();
    Trie *TrieTree8 = new Trie();
    Trie *TrieTree9 = new Trie();

    std::string input;
    std::vector<std::string> wordList;
    readFile("scrabbleWords.txt", &wordList); 
    for(int i = 0; i < wordList.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree->insert(wordList[i]);
    }
    
  bool running = true;
    bool result = false;
    
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

    std::vector<float> searchValue;
    std::vector<float> insertValue;
    std::vector<float> visualizeValue;
    std::vector<float> recursiveValue;
    unsigned long cStart , cEnd ;

    //Word: 33
    std::vector<std::string> wordList2;
    readFile("visualizationWordList.txt", &wordList2); 
    cStart = std::clock();
    for(int i = 0; i < wordList2.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree2->insert(wordList2[i]);
    }
    cEnd = std::clock();
    float time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    insertValue.push_back(time);

    cStart = std::clock();
    for(int i = 0; i < wordList2.size(); i++){
        //std::cout << wordList[i] << std::endl;
        TrieTree3->recursiveInsert(wordList2[i]);
    }
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    recursiveValue.push_back(time);


    cStart = std::clock();
    TrieTree2->visualize("graph_Visualization.dot");
    cEnd = std::clock();
    time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
    visualizeValue.push_back(time);

    //Words: 12972
    std::vector<std::string> wordList3;
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
 
//     float value;
//     unsigned long cStart , cEnd ;
    
//     // checks time for search function performance
//     if (search(root, entry)) {
//        cStart = std::clock();
//         value = search(root, entry);
//        cEnd = std::clock();

//     }
//         // checks time for insert function peformance
//     else if (insert(data, root)) {
//         cStart = std::clock();
//         value = insert(root, entry);
//         cEnd = std::clock();
       
        
//     else if (recursiveInsert(root, data, pointer){
//         cStart = std::clock();
//         value = recursiveInsert(root, data, pointer);
//         cEnd = std::clock();
     
//     else{
//         std::cout << "Please enter a valid function" << std::endl;

//     }

//     float time = 1.0 * (cEnd - cStart) / CLOCKS_PER_SEC;
        
//     std::cout << std::fixed << std::setprecision(4) << time << " Output: " << value << std::endl;
// }
