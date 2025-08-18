#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>

#include <nlohmann/json.hpp>

#include "gallow.hpp"

using namespace std;
using json = nlohmann::json;

void initializeWord();
void draw(int numberWrong);
void processInput();
void processCorrectInput(char charGuessed);
void clearScreen();
char prompt();

// string word;
// string answer;
// int incorrectGuesses = 0;

Gallow game;

// Main Function: (100% done)
int main() {
    // Prepare screen for game.
    // initializeWord();
    cout << "Welcome to Hangman!\n";

    // Game loop, goes up to but not including the lose state. 
    /*
    while (incorrectGuesses < 6) {
        draw(incorrectGuesses);
        processInput();
        bool isWon = (find(answer.begin(), answer.end(), '_') == answer.end());
        if (!isWon) {
            continue;
        } else {
            draw(incorrectGuesses);
            cout << "You win!" << endl;
            return 0;
        }
    }
    */
    while(game.checkIfWon() == false) {
        game.draw();
        game.processInput();
        if (game.checkIfLost() == true) {
            game.draw();
            cout << "You lose! The word was: \"" + game.getWord() + "\"\n";
            return 0;
        }
    }
    game.draw();
    cout << "You win! The word was: \"" + game.getWord() + "\"\n";
}

