#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<vector<int>>& rings, vector<int>& rods) {
    int n = rings.size();
    int m = rods.size();
    vector<int> dp(m+1, 0);
    for(int i=0;i<n;i++){
        vector<int> new_dp(m+1, INT_MAX);
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                int diff = abs(rods[j] - rings[i][0]);
                int score = min(diff, abs(m - diff));
                new_dp[k] = min(new_dp[k], dp[j] + score + (k != j ? rings[i][1] : 0));
            }
        }
        dp = new_dp;
    }
    int ans = INT_MAX;
    for(int i=0;i<m;i++){
        ans = min(ans, dp[i]);
    }
    return ans;
}

int main() {
    vector<vector<int>> rings = {{1,3},{2,3},{3,3}}; // Example rings
    vector<int> rods = {2,2,2,2,2}; // Example rods
    int minOps = minOperations(rings, rods);
    cout << "Minimum operations needed: " << minOps << endl;
    return 0;
}
