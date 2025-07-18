#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void draw ();
char prompt ();

int main() {
    string answer = "hello";
    draw ();
    /*if (find(answer.begin(), answer.end(), prompt()) == answer.end()) {
        cout << "Wrong!\n";
    }
    else {
        cout << "Right!\n";
    }
    return 0;*/
}

void draw () {
    // Draws the game state.
    ifstream file("gallows/gallow_1.txt");
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
