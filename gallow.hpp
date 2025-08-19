#pragma once

#include <string>
#include <fstream>
#include <random>
#include <iostream>
#include <set>

#include <nlohmann/json.hpp>

class Gallow {
 public:
    Gallow();

    std::ifstream openFile(std::string);
    void updateState();

    void initializeWord();
    void initializeAnswer();

    void draw();
    void clearScreen();

    const bool checkIfWon();
    bool checkIfLost() const;
    std::string getWord() const { return word; }

    void processInput();
 private:
    int incorrectGuesses;
    const int maxWrongGuesses = 7;
    std::string state, word, answer;
    std::set<char> guessed;
};
