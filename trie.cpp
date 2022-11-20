#include "trie.h"

void insert(Node* root, std::string entry) {
    if (root == nullptr) {
        std::cout << "Trie not found." << std::endl;
    }
    Node* currentNode = root;
    for (int i = 0; i < entry.length(); i++) {
        int index;
        if(entry[i] >= 'A' && entry[i] <= 'Z'){
            index = entry[i] - 'A';
        }
        if(entry[i] >= 'a' && entry[i] <= 'z'){
            index = entry[i] - 'a';
        }
        if (currentNode->children[index] == nullptr) {
            currentNode->children[index] = newNode(entry[i]);
            currentNode->children[index]->generation = i;
            currentNode->children[index]->value = entry[i];
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isWord = true;
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
/*
 * Public Functions
*/

Trie::Trie(){

}

Trie::~Trie(){

}

void Trie::insert(std::string data){

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
