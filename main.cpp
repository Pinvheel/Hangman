#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void draw(int numberWrong);
void processInput();
void processCorrectInput(char charGuessed);
void clearScreen();
char prompt();

string word = "hello";
string answer = "_____";
int incorrectGuesses = 0;

// Main Function: (100% done)
int main() {
    clearScreen(); // Prepare screen for game.
    cout << "Welcome to Hangman!\n";

    while (incorrectGuesses < 6) {  // Game loop, goes up to but not including the lose state.
        draw(incorrectGuesses);
        processInput();
        if (find(answer.begin(), answer.end(), '_') == answer.end()) { 
            cout << "You win!"; 
            return 0;
        }
    }

    draw(incorrectGuesses); // The aforementioned lose state.
    cout << "You lose!\n";
    return 0;
}

// Takes the number of wrong guesses and draws the game state with the corresponding number of body parts on the noose: (100% done)
void draw(int numberWrong) {
    string fileLoc = "gallows/gallow_" + to_string(numberWrong) + ".txt";   // Fetches file from gallows folder.
    ifstream file(fileLoc); string line;
    
    while (getline(file, line)) { cout << line << '\n'; }   // Draws file on screen.
    file.close();
}

// Processes what the user input to see if it is right, wrong, or invalid.
void processInput() {
    char charGuessed = prompt();
    auto countOfChar = count(word.begin(), word.end(), charGuessed);
    
    if (countOfChar == 0) {
        clearScreen();
        cout << "Wrong!\n";
        incorrectGuesses++;
        return;
    }
    else {
        processCorrectInput(charGuessed);
        return;
    }
}

void processCorrectInput(char charGuessed) {
    clearScreen();
    cout << "Right!\n";

    auto it = word.begin();
    while ((it = std::find(it, word.end(), charGuessed)) != word.end()) {
        int index = std::distance(word.begin(), it);
        answer[index] = charGuessed;
        ++it;
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
