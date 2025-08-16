#include "gallow.hpp"

Gallow::Gallow() : state(""), word(""), answer(""), incorrectGuesses(0) {
    updateState();
    initializeWord();
    initializeAnswer(word);
}

std::ifstream Gallow::openFile(std::string fileLocation) {
    std::ifstream file(fileLocation);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file:" + fileLocation);
    }
    return file;
}

void Gallow::updateState() {
    state.clear();

    std::string fileLocation = "gallows/gallow_" + std::to_string(incorrectGuesses) + ".txt";
    std::ifstream file = openFile(fileLocation); 
    std::string line;

    while (getline(file, line)) { state += line + "\n"; }
    file.close();
}

void Gallow::initializeWord() {
    using json = nlohmann::json;
    
    // Choose a random word from the words.json file
    std::ifstream file("words.json");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: words.json");
    }

    json j;
    file >> j;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, j.size() - 1);

    // Set word to it
    word = j[dist(gen)];

    for (char c : word) {
        answer += '_';
    }
}