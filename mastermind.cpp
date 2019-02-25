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
#define RESET "\033[0;0m"

#define BOLD "\033[0;1m"
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

    cout << CYAN << "-------------" << endl;
    cout << "|" <<  BOLD << YELLOW << "How to Play" << CYAN << "|" << endl;
    cout << "-------------" << RESET << endl;
    cout << "-> Type in a sequence of characters choosing from R, G, B, Y, C, M" << endl;
    cout << "-> An output box will appear. Next to your guess you will see a combination of R, I and #" << endl;
    cout << MAGENTA << "-> An R means a character (not specified) is in the right spot" << endl;
    cout << "-> An I means there is a character that is in the key but in the wrong spot" << endl;
    cout << "-> A # is simply filler" << RESET << endl;
    cout << "-> Your goal is to find the key with the information provided" << endl;
    cout << BLUE << "\nHave Fun!" << RESET << endl;
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
    string check;

    string test = key;

    for (int i = 0; i < 4; ++i) {
        if(ans[i] == key[i]){
            check += "R";
            test[i] = '0';
            ans[i] = '1';
        }
    }

    for (int j = 0; j < 4; ++j) {
       if (test.find(ans[j]) != string::npos){
           size_t index = test.find(ans[j]);

           check += "I";
           test[index] = '0';
       }
    }

    long len = 4 - check.length();

    for (int k = 0; k < len; ++k) {
        check += "#";
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

        cout << "----------------------------" << endl;
        cout << "| " << ans[0] << " - " << ans[1] << " - " << ans[2] << " - " << ans[3] << " | " << guessCheck(ans) << " | " << guesses << " |" << endl;
        cout << "----------------------------" << endl;

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
        ans.erase(remove_if(ans.begin(), ans.end(), ::isspace), ans.end());

        play = guess(ans);
    }
}