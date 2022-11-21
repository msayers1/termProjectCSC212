#include "trie_vanessa.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iomanip>

// Inserts an std::string into the trie
void Trie0::insert(Node* root, std::string entry){
    // If the trie is empty, return CBT
    if (root == nullptr) {
        std::cout << "Trie empty." << std::endl;
        return;
    }
    // Create a temporary node that will iterate through the trie
    Node* currentNode = root;
    // Loop through the length of the string being inserted
    int index;
    for (int i = 0; i < entry.length(); i++) {
        // Initialize the index variable, representing the location of the character
        if(entry[i] >= 'A' && entry[i] <= 'Z'){
            index = entry[i] - 'A';
        }
        if(entry[i] >= 'a' && entry[i] <= 'z'){
            index = entry[i] - 'a';
        }
        // If the node reached is empty...
        if (currentNode->children[index] == nullptr) {
            // Create a new node at that index
            currentNode->children[index] = new Node(entry[i]);
            // Update the node's generation - there is no generation yet. 
            //currentNode->children[index]->generation = i;
            // Add the node's value - the key is setup with new Node. 
            //currentNode->children[index]->key = entry[i];
        }
        // Travel to the next node
        currentNode = currentNode->children[index];
    }
    // Mark the last letter as the end of a word 
    currentNode->isWord = true;
    currentNode->key = entry;
    currentNode->count = currentNode->count++;
    //std::cout << entry << " was entered into the trie." << std::endl;
    
}

void Trie0::preorder(Node* root, std::ostream& os){
}

void Trie0::inorder(Node* root, std::ostream& os){
}

void Trie0::postorder(Node* root, std::ostream& os){
}

void Trie0::destroy(Node* root){

}

bool Trie0::search(std::string data, Node* root){
}

bool Trie0::remove(std::string data, Node* root){

}

void Trie0::visualize(std::ofstream* output_file, Node* root){
    Node* currentNode = root;
    Node* child;
    std::string parentKey;
    std::string childKey; 
    //std::cout << "The size:" << (*currentNode).children.size()  << std::endl;
    for(int i = 0; i < currentNode->children.size(); i++){
        child = currentNode->children[i];
        if(child != nullptr && child->isWord){
            parentKey = (currentNode->key == "")?"Root":currentNode->key;
            //std::string childKey = (child->isWord == true)?"Root":std::to_string(currentNode->key);
            //std::cout << currentNode->key << "(" << i << ")" << " -> " << child->key << std::endl;
            (*output_file) << "\"" << parentKey << "\"" << " -> " << "\"" << child->key << "\"" << ";\n";
        }else if(child != nullptr){
            parentKey = (currentNode->key == "")?"Root":currentNode->key;
            (*output_file) << "\"" << parentKey << "\"" << " -> " << "\"" << child->key << "\"" << ";\n";
            visualize(output_file, child);
        } 
    }
    return;
}
/*
 * Public Functions
*/

Trie0::Trie0(){
    this->root = new Node();

}

Trie0::~Trie0(){

}

void Trie0::insert(std::string data){
    this->insert(this->root, data);
}


void Trie0::preorder(std::ostream& os){

}

void Trie0::inorder(std::ostream& os){

}

void Trie0::postorder(std::ostream& os){

}

bool Trie0::search(std::string data){

}

bool Trie0::remove(std::string data){

}

void Trie0::visualize(std::string filename){
    std::ofstream output_file(filename);
    //std::cout << "digraph g {" << std::endl;
    output_file << "digraph g { \n";
    this->visualize(&output_file, this->root);
    output_file << "}";
    output_file.close();

    
}