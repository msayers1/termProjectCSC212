#ifndef NODE_H
#define NODE_H

#include <string>
#include <unordered_map>

class Node{
    private:
        std::string key;
        std::unordered_map<int, Node*> children;
        int count;
        bool isWord;

    public:
        // Not used. Implemented anyway.
        Node();
        Node(std::string data);
        Node(char data);

        friend class Trie;
};
#endif
