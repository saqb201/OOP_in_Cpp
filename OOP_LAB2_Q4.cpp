#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Team {
private:
    int numberOfPlayers;

public:
    Team(int numPlayers) : numberOfPlayers(numPlayers) {}

    int getNumberOfPlayers() {
        return numberOfPlayers;
    }
};

class Game {
private:
    Team yourTeam;
    int enemyHits;
    int yourHits;

public:
    Game(int numPlayers) : yourTeam(numPlayers), enemyHits(0), yourHits(0) {}

    void play() {
        cout << "Total No. Of Players in your team: " << yourTeam.getNumberOfPlayers() << endl;

        for (int i = 0; i < yourTeam.getNumberOfPlayers(); ++i) {
            int number1 = generateRandomNumber();
            int number2 = generateRandomNumber();
            cout << endl << "Pair of numbers:" << endl;
            cout << "Number1: " << number1 << endl;
            cout << "Number2: " << number2 << endl;

            if (number1 == number2) {
                cout << "Enemy got hit by your team!" << endl;
                yourHits++;
            } else {
                cout << "You got hit by the enemy team!" << endl;
                enemyHits++;
            }
        }

        cout << endl << "Game Over! ";

        if (yourHits > enemyHits) {
            cout << "You won" << endl;
        } else {
            cout << "You lost" << endl;
        }
    }

private:
    int generateRandomNumber() {
        return rand() % 6 + 1; // Generate a random number between 1 and 6
    }
};

int main() {
    srand(time(0)); // Seed the random number generator with current time

     // Generate a random number of players between 1 and 3
    int numPlayers = rand() % 3 + 1;

    Game game(numPlayers);
    game.play();

    return 0;
}