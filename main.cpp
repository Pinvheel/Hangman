#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void draw(int numberWrong);
void processInput();
char prompt();

string word = "hello";
string answer = "_____";
int incorrectGuesses = 0;

int main() {
    cout << "\033[2J\033[1;1H";
    // Draw the gamestate associated with the number of incorrect guesses.
    cout << "Welcome to Hangman!\n";
    while (incorrectGuesses < 6) {
        draw(incorrectGuesses);
        processInput();
    }
    draw(incorrectGuesses);
    cout << "You lose!\n";
    return 0;
}

void draw(int numberWrong) {
    // Draws the game state.
    string fileLoc = "gallows/gallow_" + to_string(numberWrong) + ".txt";
    ifstream file(fileLoc);
    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }
    file.close();
    return;
}

// Processes what the user input to see if it is right, wrong, or invalid.
void processInput() {
    char c = prompt();
    auto positionOfChar = find(word.begin(), word.end(), c);
    
    if (positionOfChar == word.end()) {
        cout << "\033[2J\033[1;1H";
        cout << "Wrong!\n";
        incorrectGuesses++;
        return;
    }
    else {
        cout << "\033[2J\033[1;1H";
        cout << "Right!\n";
        size_t index = distance(word.begin(), positionOfChar);
        answer[index] = c;
        return;
    }
}

char prompt() {
    // Prompts user for a single character input, & returns input.
    cout << "Input a letter in the word \"hello\"\n";
    cout << answer + "\n";
    char input;
    cin >> input;
    return input;
}
