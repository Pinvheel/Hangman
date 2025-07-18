#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void draw(int numberWrong);
void processInput();
char prompt();

string answer = "hello";
int incorrectGuesses = 0;

int main() {
    // Draw the gamestate associated with the number of incorrect guesses.
    while (incorrectGuesses < 6) {
        draw(incorrectGuesses);
        processInput();
    }
    return 0;
}

void draw(int numberWrong) {
    // Draws the game state.
    string fileLoc = "gallows/gallow_" + to_string(numberWrong) + ".txt";
    ifstream file(fileLoc);
    string line;
    while (getline(file, line)) {
        std::cout << line << '\n';
    }
    file.close();
    return;
}

// Processes what the user input to see if it is right, wrong, or invalid.
void processInput() {
    char inputChar = prompt();
    if (find(answer.begin(), answer.end(), inputChar) == answer.end()) {
        cout << "Wrong!\n";
        incorrectGuesses++;
        return;
    }
    else {
        cout << "Right!\n";
        return;
    }
}

char prompt() {
    // Prompts user for a single character input, & returns input.
    cout << "Input a letter in the word \"hello\"\n";
    char input;
    cin >> input;
    return input;
}
