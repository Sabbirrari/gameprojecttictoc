#include <iostream>
#include <string>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |"; // Add vertical dividers
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n"; // Add horizontal dividers
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // At least one cell is empty
            }
        }
    }
    return true; // All cells are filled
}

// Function to handle player moves
bool makeMove(char board[3][3], int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (move < 1 || move > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false; // Invalid move
    }
    board[row][col] = player; // Place the player's mark
    return true;
}

// Main function
int main() {
    // Initialize the game board
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    string player1, player2;

    // Get player names
    cout << "Enter Player 1's name (X): ";
    getline(cin, player1);
    cout << "Enter Player 2's name (O): ";
    getline(cin, player2);

    char currentPlayer = 'X';
    string currentName = player1;
    int move;

    cout << "\nWelcome to Tic-Tac-Toe!\n";
    displayBoard(board);

    while (true) {
        // Ask the current player for their move
        cout << currentName << " (" << currentPlayer << "), enter your move (1-9): ";
        cin >> move;

        // Handle the move
        if (makeMove(board, move, currentPlayer)) {
            displayBoard(board);

            // Check for win or draw
            if (checkWin(board, currentPlayer)) {
                cout << "Congratulations, " << currentName << "! You win!\n";
                break;
            } else if (isDraw(board)) {
                cout << "It's a draw!\n";
                break;
            }

            // Switch players
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
                currentName = player2;
            } else {
                currentPlayer = 'X';
                currentName = player1;
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    cout << "Game Over. Thanks for playing!\n";
    return 0;
}
