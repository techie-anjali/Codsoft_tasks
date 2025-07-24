// TASK3:TIC-TAC-TOE GAME
// Build a simple console-based Tic-Tac-Toe game that
// allows two players to play against each other
// Game Board: Create a 3x3 grid as the game board.
// Players: Assign"X"and "O" to two players.
// Display Board: Show the current state of the board.
// Player Input: Prompt the current player to enter their move.
// Update Board: Update the game board with the players move.
// Check for Win: Check if the current player has won.
// Check for Draw: Determine if the game is a draw.
// Switch Players: Alternate turns between"X"and "O" players.
// Display Result: Show the result of the game (win, draw, or ongoing).
// Play Again: Ask if the players want to play another game.


#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void resetBoard() {
    char ch = '1';
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = ch++;
}

void displayBoard() {
    cout << "\n";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << " " << board[i][j] << " ";
            if(j < 2) cout << "|";
        }
        if(i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

bool isWin() {
    for(int i=0; i<3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isDraw() {
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Please choose an empty position from 1 to 9.\n";
        makeMove();
    } else {
        board[row][col] = currentPlayer;
    }
}

int main() {
    char playAgain;
    do {
        resetBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while(!gameOver) {
            displayBoard();
            makeMove();

            if(isWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins the game!\n";
                gameOver = true;
            } else if(isDraw()) {
                displayBoard();
                cout << "The game ended in a draw.\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing. See you next time!\n";
    return 0;
}
