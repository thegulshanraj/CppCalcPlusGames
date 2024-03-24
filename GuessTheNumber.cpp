#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_RANGE = 100;
const int EASY = 1;
const int MEDIUM = 2;
const int DIFFICULT = 3;
const int MAX_ATTEMPTS_EASY = 10;
const int MAX_ATTEMPTS_MEDIUM = 7;
const int MAX_ATTEMPTS_DIFFICULT = 5;

void displayInstructions()
{
    cout << "\n\t\t\tWelcome to GuessTheNumber game!" << endl;
    cout << "You have to guess a number between 1 and " << MAX_RANGE << ". "
                                                                        "You'll have limited choices based on the "
                                                                        "level you choose. Good Luck!"
         << endl;
}

int getDifficultyLevel()
{
    int level;
    cout << "\nEnter the difficulty level: \n";
    cout << EASY << " for easy!\t";
    cout << MEDIUM << " for medium!\t";
    cout << DIFFICULT << " for difficult!\t";
    cout << "0 for ending the game!\n"
         << endl;

    while (true)
    {
        cout << "Enter the number: ";
        cin >> level;

        if (cin.fail() || level < 0 || level > DIFFICULT)
        {
            cout << "Invalid input. Please enter a valid number between 0 and " << DIFFICULT << "." << endl;
            cin.clear();               // Clear the error flag
            cin.ignore(INT_MAX, '\n'); // Discard invalid input
        }
        else
        {
            break; // Valid input, exit the loop
        }
    }

    return level;
}

int generateSecretNumber()
{
    srand(time(0));
    return 1 + (rand() % MAX_RANGE);
}

void playGame(int chosenDifficulty)
{
    int secretNumber = generateSecretNumber();
    int userGuess;

    int maxAttempts;
    if (chosenDifficulty == EASY)
    {
        maxAttempts = MAX_ATTEMPTS_EASY;
    }
    else if (chosenDifficulty == MEDIUM)
    {
        maxAttempts = MAX_ATTEMPTS_MEDIUM;
    }
    else if (chosenDifficulty == DIFFICULT)
    {
        maxAttempts = MAX_ATTEMPTS_DIFFICULT;
    }

    cout << "\nYou have " << maxAttempts << " choices for finding the "
                                            "secret number between 1 and "
         << MAX_RANGE << "." << endl;

    for (int attemptsLeft = maxAttempts; attemptsLeft > 0; --attemptsLeft)
    {
        while (true)
        {
            cout << "\n\nEnter your guess: ";
            cin >> userGuess;

            if (cin.fail() || userGuess < 1 || userGuess > MAX_RANGE)
            {
                cout << "Invalid input. Please enter a valid number between 1 and " << MAX_RANGE << "." << endl;
                cin.clear();               // Clear the error flag
                cin.ignore(INT_MAX, '\n'); // Discard invalid input
            }
            else
            {
                break; // Valid input, exit the loop
            }
        }

        if (userGuess == secretNumber)
        {
            cout << "Congratulations! You guessed it! The secret number is " << secretNumber << endl;
            cout << "\t\t\t Thanks for playing...." << endl;
            cout << "Play the game again with us!!\n\n"
                 << endl;
            return;
        }
        else
        {
            cout << "Incorrect guess. ";
            if (userGuess > secretNumber)
            {
                cout << "The secret number is smaller than the number you have chosen." << endl;
            }
            else
            {
                cout << "The secret number is greater than the number you have chosen." << endl;
            }

            cout << attemptsLeft - 1 << " attempts left." << endl;

            if (attemptsLeft == 1)
            {
                cout << "You couldn't find the secret number. It was " << secretNumber << ". You lose!!\n\n";
                cout << "Play the game again to win!!!\n\n";
            }
        }
    }
}

int main()
{
    while (true)
    {
        displayInstructions();
        int chosenDifficulty = getDifficultyLevel();

        if (chosenDifficulty == 0)
        {
            return 0;
        }

        playGame(chosenDifficulty);
    }

    return 0;
}
