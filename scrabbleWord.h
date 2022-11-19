#include <string>
#include <vector>

class ScrabbleWord{
    private:
        std::string word;
        int points;
        std:vector<std::pair<char,int>>;
    public:
        // Not used. Implemented anyway.
        ScrabbleWord();
        ScrabbleWord(std::string data);

};