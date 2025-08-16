#pragma once

#include <string>
#include <fstream>
#include <random>

#include <nlohmann/json.hpp>

class Gallow {
 public:
    Gallow();

    std::ifstream openFile(std::string);
    void updateState();

    void initializeWord();
    void initializeAnswer(std::string);
 private:
    int incorrectGuesses = 0;
    std::string state, word, answer;
};