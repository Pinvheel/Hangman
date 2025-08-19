#include <iostream>
#include <string>

#include "gallow.hpp"

Gallow game;

int main() {
    using std::cout;
    cout << "Welcome to Hangman!\n";

    while (game.checkIfWon() == false) {
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

