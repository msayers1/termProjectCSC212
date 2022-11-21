#include "trie.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iomanip>

Node* Trie::insert(std::string data, Node* root, int pointer){
    if(pointer == (data.length() - 1)){
        //std::cout << data << std::endl;
        return new Node(data);
    }
    Node* currentNode = root;
    pointer++;
    int letter = int(data[pointer]);
    std::string letterStr = std::to_string(data[pointer]);
    if(65 <= letter && letter <= 90){
        letter = letter + 32;
    }
    std::vector<Node*>* children = &root->children;
    if((*children)[letter] != nullptr){
        currentNode = root->children[letter];
    } else {
        currentNode = new Node(letterStr);
    }
    temp = this->insert(data, currentNode, pointer);

    //std::cout << letter <<  typeid((*currentNode).children).name() << std::endl;
    // if(!(*currentNode).children[(*temp).key])
    //     (*currentNode).children[(*temp).key] = temp;
    // if(!root->children[letter]){
    //     (*root).children[letter] = currentNode;
    // }
    //std::cout << (*root).key << " -> " << (*currentNode).key << std::endl;
    //std::cout << (*currentNode).key << " -> " << std::endl;
    //(*currentNode).children.push_back(temp);
    //(*currentNode).count++;
    //q(*root).children.push_back(currentNode);
    return root;
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
    std::cout << "The size:" << (*currentNode).children.size()  << std::endl;
    // for(int i = 0; i < (*currentNode).children.size(); i++){
    //     child = (*currentNode).children[i];
    //     std::cout << (*currentNode).key << "(" << i << ")" << " -> " << (*child).key << std::endl;
    //     //(*output_file) << (*currentNode).key << " -> " << (*child).key << ";\n";
    //     std::cout << (*child).key << std::endl;
    //     visualize(output_file, child);

    // }
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
    this->root = this->insert(data, this->root);
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
    output_file.close();
}