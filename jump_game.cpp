#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxJump = 0;
    for (int i = 0; i < n; i++) {
        if (maxJump < i) {
            return false; // Cannot jump to current position
        }
        maxJump = max(maxJump, i + nums[i]);
        if (maxJump >= n - 1) {
            return true; // Reach the last position
        }
    }
    return false;
}

int main() {
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << canJump(nums1) << endl; // Output: 1 (true)
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << canJump(nums2) << endl; // Output: 0 (false)
    return 0;
}
