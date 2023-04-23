#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 15;
const int INF = 1e9;

int n, dist[MAXN][MAXN], memo[MAXN][1 << MAXN];

int tsp(int pos, int visited) {
    if (visited == (1 << n) - 1) return dist[pos][0]; // Base case: all nodes have been visited

    if (memo[pos][visited] != -1) return memo[pos][visited]; // Memoization

    int ans = INF;

    for (int i = 0; i < n; i++) {
        if (!(visited & (1 << i))) { // If node i has not been visited yet
            ans = min(ans, dist[pos][i] + tsp(i, visited | (1 << i))); // Recurse to next node
        }
    }

    return memo[pos][visited] = ans; // Store the result in the memo table
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    memset(memo, -1, sizeof memo); // Initialize memo table to -1

    int ans = tsp(0, 1); // Start at node 0, with node 0 already visited

    cout << ans << endl;

    return 0;
}
