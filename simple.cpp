#include <iostream>   // std::cout
#include <string>
#include <vector>

int main(){
    // std::vector<int*>temp(26, nullptr);
    // std::cout << temp.size() << std::endl;
    // temp[2] = new int(3);
    // std::cout << temp.size() << std::endl;
    // std::cout << int('a') << std::endl;
    // std::cout << int('z') << std::endl;
    // std::cout << int('A') << std::endl;
    // std::cout << int('Z') << std::endl;
    // std::cout << (char('a') - int('a'))  << std::endl;
    // std::cout << (int('z') - int('Z')) << std::endl;
    //     std::cout << (int('A') - int('Z')) << std::endl;
        std::string word = "wordDHKSNnndn";
        int test;
        char testChar;
        for(int i = 0; i < word.size(); i++){
            test = int(word[i]);
            //std::cout << word[i] << "/" << test << "/" << (65 <= test && test <= 90) <<std::endl;
            if(65 <= test && test <= 90){
                test = test + 32;
            }
            testChar = char(word[i]);
            std::string testString(1, word[i]);
            std::cout << testString << "/" << testChar << "/" << test << std::endl;
        }
        // std::cout << test << std::endl;
       for(int i=97; i <= 122; i++){
                // std::cout << char(i) << std::endl;
        }
}