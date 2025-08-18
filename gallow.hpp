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

    bool checkIfWon();
    bool checkIfLost();

    void processInput();
 private:
    int incorrectGuesses;
    bool isWon;
    std::string state, word, answer;
    std::set<char> guessed;
};