#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // Check box
    int boxRow = row / 3 * 3;
    int boxCol = col / 3 * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudokuHelper(vector<vector<char>>& board, int row, int col) {
    if (row == 9) {
        return true; // Base case: all rows filled
    }
    if (col == 9) {
        return solveSudokuHelper(board, row + 1, 0); // Move to next row
    }
    if (board[row][col] != '.') {
        return solveSudokuHelper(board, row, col + 1); // Move to next column
    }
    for (char num = '1'; num <= '9'; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudokuHelper(board, row, col + 1)) {
                return true;
            }
            board[row][col] = '.'; // Backtrack
        }
    }
    return false; // No valid number found
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuHelper(board, 0, 0);
}

int main() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
