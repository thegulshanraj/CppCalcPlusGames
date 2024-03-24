#include <iostream>
#include <cstdlib>
#include <limits> // Include the header for std::numeric_limits

using namespace std;

char gameBoard[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int playerChoice;
int row, column;
char currentPlayer = 'X';
bool isGameDraw = false;

void displayBoard()
{
    system("cls"); // Clear the screen
    cout << "Tic Tac Toe Game\n\n";
    cout << "PLAYER [X] vs PLAYER [O]\n\n";
    cout << "     |     |     \n";
    cout << "  " << gameBoard[0][0] << "  |  " << gameBoard[0][1] << "  |  " << gameBoard[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << gameBoard[1][0] << "  |  " << gameBoard[1][1] << "  |  " << gameBoard[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << gameBoard[2][0] << "  |  " << gameBoard[2][1] << "  |  " << gameBoard[2][2] << "\n";
    cout << "     |     |     \n\n";
}

void playerMove()
{
    cout << "Player " << currentPlayer << ", enter a number (1-9) to make your move: ";

    // Check for valid input
    while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > 9)
    {
        cout << "Invalid input! Please enter a number between 1 and 9.\n";

        // Clear the input buffer to handle non-numeric input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Convert choice to board indices
    row = (playerChoice - 1) / 3;
    column = (playerChoice - 1) % 3;

    // Check for valid move
    while (gameBoard[row][column] == 'X' || gameBoard[row][column] == 'O')
    {
        cout << "Invalid move! Please choose an unoccupied position.\n";
        cout << "Player " << currentPlayer << ", enter a number (1-9) to make your move: ";

        // Check for valid input
        while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > 9)
        {
            cout << "Invalid input! Please enter a number between 1 and 9.\n";

            // Clear the input buffer to handle non-numeric input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Convert choice to board indices
        row = (playerChoice - 1) / 3;
        column = (playerChoice - 1) % 3;
    }

    gameBoard[row][column] = currentPlayer;
}

bool isGameOver()
{
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++)
    {
        if ((gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2]) ||
            (gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i]))
        {
            return false; // Win
        }
    }

    // Check diagonals for a win
    if ((gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2]) ||
        (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0]))
    {
        return false; // Win
    }

    // Check for draw or continue
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O')
            {
                return true; // Continue
            }
        }
    }

    // Draw
    isGameDraw = true;
    return false;
}

int main()
{
    char playAgain;

    do
    {
        cout << "Welcome to Tic Tac Toe!\n";
        cout << "-------------------------\n\n";

        while (isGameOver())
        {
            displayBoard();
            playerMove();
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        }

        displayBoard();

        if (!isGameDraw)
        {
            cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins! Congratulations!\n";
        }
        else
        {
            cout << "It's a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        while (!(cin >> playAgain) || (tolower(playAgain) != 'y' && tolower(playAgain) != 'n'))
        {
            cout << "Invalid input! Please enter 'y' or 'n'.\n";

            // Clear the input buffer to handle non-character input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (tolower(playAgain) == 'y')
        {
            // Reset the game
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    gameBoard[i][j] = '1' + (i * 3) + j;
                }
            }
            currentPlayer = 'X';
            isGameDraw = false;
        }

    } while (tolower(playAgain) == 'y');

    cout << "Thank you for playing Tic Tac Toe!\n";

    return 0;
}
