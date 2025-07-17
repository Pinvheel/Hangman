#include <iostream>
#include <algorithm>
using namespace std;

char prompt ();

int main() {
    string answer = "hello";
    
    if (find(answer.begin(), answer.end(), prompt()) == answer.end()) {
        cout << "Wrong!\n";
    }
    else {
        cout << "Right!\n";
    }
    return 0;
}

void draw () {
    // Draws the game state.
    // Calls prompt.
}

char prompt () {
    // Prompts user for a single character input, & returns input.
    cout << "Input a letter in the word \"hello\"\n";
    char input = cin.get();
    return input;
}