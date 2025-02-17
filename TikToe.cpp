#include <iostream>

using namespace std;

void GameRules() {
    cout << "Tic-Tac-Toe Rules\n";
    cout << "Game board a 3x3 grid (classic version).\n";
    cout << "Player one uses 'X', the other uses 'O'.\n";
    cout << "Players take turns placing their mark in an empty cell.\n";
    cout << "Goal: Line up three of your marks in a row (horizontally, vertically, or diagonally).\n";
    cout << "Game ends when a player wins or the board is full (resulting in a draw).\n\n";
}

const int SIZE = 3;
char Field[SIZE][SIZE] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };

void DrawField(char arr[][SIZE], int SIZE) {
    cout << "  1   2   3\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "  ---------\n";
    }
    cout << "\n";
}

bool GameWin() {
    // Проверка по горизонтали и вертикали
    for (int i = 0; i < SIZE; i++) {
        if (Field[i][0] != '-' && Field[i][0] == Field[i][1] && Field[i][1] == Field[i][2]) {
            cout << "Player " << (Field[i][0] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
            return true;
        }
        if (Field[0][i] != '-' && Field[0][i] == Field[1][i] && Field[1][i] == Field[2][i]) {
            cout << "Player " << (Field[0][i] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
            return true;
        }
    }

    // Проверка по диагонали
    if (Field[0][0] != '-' && Field[0][0] == Field[1][1] && Field[1][1] == Field[2][2]) {
        cout << "Player " << (Field[0][0] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
        return true;
    }
    if (Field[0][2] != '-' && Field[0][2] == Field[1][1] && Field[1][1] == Field[2][0]) {
        cout << "Player " << (Field[0][2] == 'X' ? "1 (X)" : "2 (O)") << " wins!\n";
        return true;
    }

    return false;
}

bool PlayerMove(char symbol) {
    int row, col;

    while (true) {
        cout << "Player " << (symbol == 'X' ? "1 (X)" : "2 (O)") << ", enter row and column (1-3): ";
        cin >> row >> col;

        if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
            cout << "Invalid input. Please enter numbers between 1 and 3.\n";
            continue;
        }

        if (Field[row - 1][col - 1] != '-') {
            cout << "Cell already taken! Choose another one.\n";
        }
        else {
            Field[row - 1][col - 1] = symbol;
            break;
        }
    }

    DrawField(Field, SIZE);
    return true;
}

int main() {
    GameRules();
    DrawField(Field, SIZE);

    for (int turn = 0; turn < 9; turn++) {
        char currentPlayer = (turn % 2 == 0) ? 'X' : 'O';
        PlayerMove(currentPlayer);
        if (GameWin()) {
            cout << "Game Over!\n";
            return 0;
        }
    }

    cout << "It's a draw!\n";
    return 0;
}
