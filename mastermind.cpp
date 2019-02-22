//
// Created by gabe on 2/14/19.
//

#include <string>
#include <algorithm>
#include <iostream>
#include <experimental/random>
#include "mastermind.h"

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
using namespace std;

int mastermind::code() {
    key = "";

    string col[6] = {"R", "M", "Y", "G", "B", "C"};

    for (int i = 0; i < 4; ++i) {
        int rando = experimental::randint(0, 6);
        key += col[rando];
    }

    return 0;
}

void mastermind::startGame() {
    code();
    guesses = 0;
}

int mastermind::goalTest(string ans) {
    if(ans == key){
        return 1;
    } else {
        return 0;
    }
}

int mastermind::failTest() {
    if(guesses >= 10){
        return 1;
    } else {
        return 0;
    }
}

string mastermind::guessCheck(std::string ans) {
    string check, guessed;

    for (int i = 0; i < 4; ++i) {
        if(ans[i] == key[i]){
            check += "R";
        } else if (key.find(ans[i]) != string::npos) {
            check += "I";
            guessed += ans[i];
        }
    }

    return check;
}

int mastermind::guess(std::string ans) {
    if(goalTest(ans)) {
        cout << GREEN << "You Won!" << endl;
        return 1;
    } else if (failTest()) {
        cout << RED << "You Lost!" << endl;
        return 2;
    } else {
        ++guesses;

        cout << "---------------------------" << endl;
        cout << "| " << ans[0] << " - " << ans[1] << " - " << ans[2] << " - " << ans[3] << " | " << guessCheck(ans) << " | " << guesses << " |" << endl;
        cout << "---------------------------" << endl;

        return 0;
    }
}

void mastermind::playGame() {
    int play = 0;

    while(!play) {

        cout << "Enter your guess: ";
        string ans;
        getline(cin, ans);

        transform(ans.begin(), ans.end(), ans.begin(), ::toupper);

        play = guess(ans);
    }
}