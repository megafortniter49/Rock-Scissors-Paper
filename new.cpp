#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice {ROCK, SCISSORS, PAPER};

Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

Choice getUserChoice() {
    int choice;
    cout << "Enter 0 for Rock, 1 for Scissors, 2 for Paper: ";
    cin >> choice;
    return static_cast<Choice>(choice);
}

string choiceToString(Choice choice) {
    switch (choice) {
        case ROCK: return "Rock";
        case SCISSORS: return "Scissors";
        case PAPER: return "Paper";
        default: return "Invalid Choice";
    }
}

void determineWinner(Choice userChoice, Choice computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == SCISSORS && computerChoice == PAPER) ||
               (userChoice == PAPER && computerChoice == ROCK)) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
}

int main() {
    srand(time(0)); // Seed for random number generator

    Choice userChoice = getUserChoice();
    Choice computerChoice = getComputerChoice();

    cout << "You chose: " << choiceToString(userChoice) << endl;
    cout << "Computer chose: " << choiceToString(computerChoice) << endl;

    determineWinner(userChoice, computerChoice);

    return 0;
}
