#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); // Sort the input array
    int closestSum = INT_MAX;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return target;
            }
            // Update the closest sum if the current sum is closer to the target
            if (abs(sum - target) < abs(closestSum - target)) {
                closestSum = sum;
            }
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return closestSum;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int closestSum = threeSumClosest(nums, target);
    cout << "The closest sum to " << target << " is " << closestSum << endl;
    return 0;
}
