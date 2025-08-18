#include "gallow.hpp"

Gallow::Gallow() : state(""), word(""), answer(""), incorrectGuesses(0), isWon(false) {
    updateState();
    initializeWord();
    initializeAnswer();
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

    std::string fileLocation;
    if (isWon) fileLocation = "gallows/gallow_victory.txt";
    else if (incorrectGuesses >= 7) fileLocation = "gallows/gallow_loss.txt";
    else fileLocation = "gallows/gallow_" + std::to_string(incorrectGuesses) + ".txt";
    std::ifstream file = openFile(fileLocation); 
    std::string line;

    while (getline(file, line)) { state += line + "\n"; }
    file.close();
}

void Gallow::initializeWord() {
    using json = nlohmann::json;
    
    std::ifstream file = openFile("words.json");

    json j;
    file >> j;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, j.size() - 1);

    word = j[dist(gen)];
}

void Gallow::initializeAnswer() {
    for (char c : word) {
        answer += '_';
    }
}

void Gallow::draw() {
    clearScreen();
    updateState();
    std::cout << state;
}

void Gallow::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}


bool Gallow::checkIfWon() {
    if (answer == word) isWon = true;
    return isWon;
}

bool Gallow::checkIfLost() {
    if (incorrectGuesses >= 7) return true;
    else return false;
}

void Gallow::processInput() {
    std::cout << "Input a letter that could be in this word:\n";
    std::cout << answer + "\n";
    char c;
    std::cin >> c;
    if (guessed.count(c)) {
        std::cout << "Already guessed char " + c;
        return;
    }

    guessed.insert(c);
    size_t notFound = std::string::npos;

    if (word.find(c) == notFound){
        std::cout << "Wrong!\n";
        incorrectGuesses++;
    } else {
        for (int i = 0; i < word.size(); i++)
            if(word[i] == c) answer[i] = c;
    }
}