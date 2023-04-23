#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    // Sort the array
    sort(nums.begin(), nums.end());

    int sum = 0;
    // Take the sum of every other element starting from index 0
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    // Example usage
    vector<int> nums = {1,4,3,2};
    int result = arrayPairSum(nums);
    cout << "Result: " << result << endl;

    return 0;
}
