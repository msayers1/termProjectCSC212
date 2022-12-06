//node.cpp    
#include "node.h"
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string

    Node::Node(){
        this->key = "";
        std::vector<Node*>temp(26, nullptr);
        this->children = temp;  
        this->numChildren = 0;
        this->count = 0;
        this->isWord = false;
    };
    Node::Node(char data){
        std::string string(1, data);
        this->key = string;
        std::vector<Node*>temp(26, nullptr);
        this->children = temp;   
        this->numChildren = 0;
        this->count = 0;
        this->isWord = false;
    };
    Node::Node(std::string data){
        this->key = data;
        this->isWord = true;
        this->count = true;
    };
