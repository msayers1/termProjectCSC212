#include <string>
#include <vector>

class Node{
    private:
        std::string key;
        std::vector<Node*> children;
        int count;

    public:
        // Not used. Implemented anyway.
        Node();
        Node(std::string data);

        friend class Trie;
};