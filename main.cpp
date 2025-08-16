#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>

#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void initializeWord();
void draw(int numberWrong);
void processInput();
void processCorrectInput(char charGuessed);
void clearScreen();
char prompt();

string word;
string answer;
int incorrectGuesses = 0;

// Main Function: (100% done)
int main() {
    clearScreen(); // Prepare screen for game.
    initializeWord();
    cout << "Welcome to Hangman!\n";

    while (incorrectGuesses < 6) {  // Game loop, goes up to but not including the lose state.
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

    draw(incorrectGuesses); // The aforementioned lose state.
    cout << "You lose!\n";
    return 0;
}

void initializeWord() {
    // Choose a random word from the words.json file
    ifstream file("words.json");
    if(!file.is_open()) {
        throw runtime_error("Could not open file: words.json");
    }

    json j;
    file >> j;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, j.size() - 1);

    // Set word to it
    word = j[dist(gen)];

    // For each letter in word, create an answer string with all the letters replaced with _
    for (char c : word) {
        answer += '_';
    }
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
    cout << "Input a letter that could be in this word:\n";
    cout << answer + "\n";
    char input;
    cin >> input;
    return input;
}
