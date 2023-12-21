#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

// Function to get the computer's choice
Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

// Function to determine the winner of the game
void determineWinner(Choice userChoice, Choice computerChoice) {
    cout << "Computer chose ";
    switch (computerChoice) {
        case ROCK:
            cout << "rock.";
            break;
        case PAPER:
            cout << "paper.";
            break;
        case SCISSORS:
            cout << "scissors.";
            break;
    }
    cout << endl;

    cout << "You chose ";
    switch (userChoice) {
        case ROCK:
            cout << "rock.";
            break;
        case PAPER:
            cout << "paper.";
            break;
        case SCISSORS:
            cout << "scissors.";
            break;
    }
    cout << endl;

    // Determine the winner
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == PAPER && computerChoice == ROCK) ||
               (userChoice == SCISSORS && computerChoice == PAPER)) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed for random number generation

    cout << "Rock, Paper, Scissors Game" << endl;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting the Rock, Paper, Scissors Game. Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl << endl;
            continue;
        }

        Choice userChoice = static_cast<Choice>(choice - 1);  // Convert to enum

        Choice computerChoice = getComputerChoice();

        determineWinner(userChoice, computerChoice);

        cout << endl;
    }

    return 0;
}
