#include <iostream>
using namespace std;
char gameBoard[3][3] = { {'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'} };

int currentPlayer = 1; // Player 1 starts

void drawGameBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << gameBoard[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
}

bool isMoveValid(int row, int col) {
    // Check if the chosen cell is within the boundaries and not already taken
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] != 'X' && gameBoard[row][col] != 'O');
}

bool checkWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
            return true; // Check rows
        }
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
            return true; // Check columns
        }
    }
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
        return true; // Check diagonal (top-left to bottom-right)
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
        return true; // Check diagonal (top-right to bottom-left)
    }
    return false;
}

bool isBoardFull() {
    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    int row, col;

    do {
        // Display the current game board
        drawGameBoard();

        // Get the move from the current player
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Validate the move
        if (isMoveValid(row - 1, col - 1)) {
            gameBoard[row - 1][col - 1] = (currentPlayer == 1) ? 'X' : 'O';

            // Check for a win
            if (checkWin()) {
                drawGameBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }

            // Check for a tie
            if (isBoardFull()) {
                drawGameBoard();
                std::cout << "It's a tie!" << std::endl;
                break;
            }

            // Switch to the next player
            switchPlayer();
        }
        else {
            std::cout << "Invalid move! Please try again." << std::endl;
        }

    } while (true);

    return 0;
}
/*
int main() {
    int x;

}
*/