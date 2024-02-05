#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    bool correctGuess = false;

    cout << "Guess a number between 1 and 100: ";
    while (!correctGuess) {
        cin >> userGuess;
        if (userGuess > randomNumber) {
            cout << "Too high! Try again: ";
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again: ";
        } else {
            correctGuess = true;
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
        }
    }

    return 0;
}
