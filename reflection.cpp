#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix1);
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1.size(); j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    // Output: 7 4 1
    //         8 5 2
    //         9 6 3

    vector<vector<int>> matrix2 = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix2);
    for (int i = 0; i < matrix2.size(); i++) {
        for (int j = 0; j < matrix2.size(); j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    // Output: 15 13 2  5
    //         14 3  4  1
    //         12 6  8  9
    //         16 7  10 11

    return 0;
}
