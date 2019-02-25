//
// Created by erev on 2/14/19.
//

#ifndef CPRACTICE_MASTERMIND_H
#define CPRACTICE_MASTERMIND_H

#include <string>

class mastermind {
public:
    void startGame();
    void playGame();
protected:
    std::string key = "CCCY";
    int guesses = 0;
private:
    int guess(std::string ans);
    int goalTest(std::string ans);
    int failTest();
    int code();
    std::string guessCheck(std::string ans);
};


#endif //CPRACTICE_MASTERMIND_H
