#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<string>& board) {
    for (auto& row : board) {
        cout << row << endl;
    }
    cout << endl;
}

bool isValid(vector<string>& board, int row, int col) {
    // Check if the column has a queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }
    // Check if the diagonal has a queen
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    // Check if the opposite diagonal has a queen
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void backtrack(vector<string>& board, int row, int& count) {
    if (row == board.size()) {
        // Found a valid solution
        count++;
        printBoard(board);
        return;
    }
    for (int col = 0; col < board.size(); col++) {
        if (isValid(board, row, col)) {
            board[row][col] = 'Q';
            backtrack(board, row + 1, count);
            board[row][col] = '.';
        }
    }
}

int totalNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    int count = 0;
    backtrack(board, 0, count);
    return count;
}

int main() {
    int n = 4;
    int count = totalNQueens(n);
    cout << "Total solutions for " << n << "-queens problem: " << count << endl;
    return 0;
}
