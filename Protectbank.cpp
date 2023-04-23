#include <iostream>
#include <vector>
using namespace std;

int minBankLasers(vector<vector<int>>& banks) {
    int n = banks.size();
    int count = 0;
    bool found = true;
    while(found){
        found = false;
        vector<bool> removed(n, false);
        for(int i=0;i<n;i++){
            if(!removed[i] && banks[i][1] == 0){
                removed[i] = true;
                found = true;
                count++;
                for(int j=0;j<n;j++){
                    if(!removed[j] && banks[j][0] <= banks[i][0] && banks[j][1] >= banks[i][1]){
                        removed[j] = true;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> banks = {{2,2},{2,0},{3,1},{1,0},{4,4},{0,0},{1,1},{2,1},{4,3},{0,2}}; // Example bank layout
    int minLasers = minBankLasers(banks);
    cout << "Minimum number of lasers needed: " << minLasers << endl;
    return 0;
}
