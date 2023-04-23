#include <iostream>
#include <vector>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size();
    int ans = 0;
    for(int i=0;i<n-1;i++){
        int dx = abs(points[i+1][0] - points[i][0]);
        int dy = abs(points[i+1][1] - points[i][1]);
        ans += max(dx, dy);
    }
    return ans;
}

int main() {
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}}; // Example set of points
    int minTime = minTimeToVisitAllPoints(points);
    cout << "Minimum time to visit all points: " << minTime << endl;
    return 0;
}
