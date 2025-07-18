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

// Main Function: (100% done)
int main() {
    // Prepare screen for game.
    clearScreen();
    cout << "Welcome to Hangman!\n";
    // Game loop, goes up to but not including the lose state.
    while (incorrectGuesses < 6) {
        draw(incorrectGuesses);
        processInput();
    }
    // The aforementioned lose state.
    draw(incorrectGuesses);
    cout << "You lose!\n";
    // Return without error.
    return 0;
}

// Takes the number of wrong guesses and draws the game state with the corresponding number of body parts on the noose: (100% done)
void draw(int numberWrong) {
    // Fetches file from gallows folder.
    string fileLoc = "gallows/gallow_" + to_string(numberWrong) + ".txt";
    ifstream file(fileLoc); string line;
    
    // Draws file on screen.
    while (getline(file, line)) { cout << line << '\n'; }
    file.close();

    return;
}

// Processes what the user input to see if it is right, wrong, or invalid.
void processInput() {
    char c = prompt();
    auto positionOfChar = find(word.begin(), word.end(), c);
    
    if (positionOfChar == word.end()) {
        clearScreen();
        cout << "Wrong!\n";
        incorrectGuesses++;
        return;
    }
    else {
        clearScreen();
        cout << "Right!\n";
        size_t index = distance(word.begin(), positionOfChar);
        answer[index] = c;
        return;
    }
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

char prompt() {
    // Prompts user for a single character input, & returns input.
    cout << "Input a letter in the word \"hello\"\n";
    cout << answer + "\n";
    char input;
    cin >> input;
    return input;
}
