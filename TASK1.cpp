//TASK 1:NUMBER GUESSING GAME
// Create a program that generates a random number and asks the
// user to guess it. Provide feedback on whether the guess is too
// high or too low until the user guesses the correct number.


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));              
    int secret = rand() % 100 + 1; 
    int guess;

    cout << "I'm thinking of a number (1-100). Can you guess it?\n";

    while (true) {
        cout << "Your guess: ";
        cin >> guess;

        if (guess < secret)
            cout << "Too low \n";
        else if (guess > secret)
            cout << "Too high \n";
        else {
            cout << "You got it! The number was " << secret << ".\n";
            break;
        }
    }

    return 0;
}
