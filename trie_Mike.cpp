#include "trie_Mike.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iomanip>

void Trie::insert(std::string data, Node* root, int pointer){
    // If the trie is empty, return CBT
    if (root == nullptr) {
        std::cout << "Trie empty." << std::endl;
        return;
    }
    // Create a temporary node that will iterate through the trie
    Node* currentNode = root;
    // Loop through the length of the string being inserted
    int index;
    for (int i = 0; i < data.length(); i++) {
        // Initialize the index variable, representing the location of the character
        if(data[i] >= 'A' && data[i] <= 'Z'){
            index = data[i] - 'A';
        }
        if(data[i] >= 'a' && data[i] <= 'z'){
            index = data[i] - 'a';
        }
        // If the node reached is empty...
        if (currentNode->children[index] == nullptr) {
            // Create a new node at that index
            currentNode->children[index] = new Node(data[i]);
            // Update the node's generation - there is no generation yet. 
            //currentNode->children[index]->generation = i;
            // Add the node's value - the key is setup with new Node. 
            //currentNode->children[index]->key = data[i];
        }
        // Travel to the next node
        currentNode = currentNode->children[index];
    }
    // Mark the last letter as the end of a word 
    
    //std::cout << entry << " was entered into the trie." << std::endl;
    
}


void Trie::preorder(Node* root, std::ostream& os){
}

void Trie::inorder(Node* root, std::ostream& os){
}

void Trie::postorder(Node* root, std::ostream& os){
}

void Trie::destroy(Node* root){

}

bool Trie::search(std::string data, Node* root){
}

bool Trie::remove(std::string data, Node* root){

}


void Trie::visualize(std::ofstream* output_file, Node* root){
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

Trie::Trie(){
    this->root = new Node("root");
}

Trie::~Trie(){

}

void Trie::insert(std::string data){
    this->insert(data, this->root);
}


void Trie::preorder(std::ostream& os){

}

void Trie::inorder(std::ostream& os){

}

void Trie::postorder(std::ostream& os){

}

bool Trie::search(std::string data){

}

bool Trie::remove(std::string data){

}

void Trie::visualize(std::string filename){
     std::ofstream output_file(filename);
    //std::cout << "digraph g {" << std::endl;
    output_file << "digraph g { \n";
    this->visualize(&output_file, this->root);
    output_file << "}";
    output_file.close();
}