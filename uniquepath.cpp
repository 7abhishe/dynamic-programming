#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    // Initialize a 2D vector to store the number of unique paths to each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // The number of unique paths to the first row and column is always 1
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    
    // Calculate the number of unique paths to each cell
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    // The number of unique paths to the bottom-right cell is the answer
    return dp[m-1][n-1];
}

int main() {
    int m = 3, n = 7;
    int numPaths = uniquePaths(m, n);
    cout << "Number of unique paths from top-left to bottom-right: " << numPaths << endl;
    return 0;
}
