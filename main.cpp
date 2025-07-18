#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void draw (int numberWrong);
char prompt ();

int main() {
    string answer = "hello";
    int incorrectGuesses = 0;
    draw(incorrectGuesses);
    /*if (find(answer.begin(), answer.end(), prompt()) == answer.end()) {
        cout << "Wrong!\n";
    }
    else {
        cout << "Right!\n";
    }
    return 0;*/
}

void draw (int numberWrong) {
    // Draws the game state.
    string fileLoc = "gallows/gallow_" + to_string(numberWrong) + ".txt";
    ifstream file(fileLoc);
    string line;
    while (getline(file, line)) {
        std::cout << line << '\n';
    }
    file.close();
    // Calls prompt.
}

char prompt () {
    // Prompts user for a single character input, & returns input.
    cout << "Input a letter in the word \"hello\"\n";
    char input = cin.get();
    return input;
}
