#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int maxArea = 0;

    while (left < right) {
        int currArea = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, currArea);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxAreaValue = maxArea(height);
    cout << "The maximum area of water that can be contained is " << maxAreaValue << endl;
    return 0;
}
