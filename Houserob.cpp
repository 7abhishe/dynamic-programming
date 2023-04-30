#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxMoney(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(findMaxMoney(nums, 0, n-2), findMaxMoney(nums, 1, n-1));
    }
    
    int findMaxMoney(vector<int>& nums, int start, int end) {
        int prevRobbed = 0, prevNotRobbed = 0;
        for(int i=start; i<=end; i++) {
            int currRobbed = prevNotRobbed + nums[i];
            int currNotRobbed = max(prevRobbed, prevNotRobbed);
            prevRobbed = currRobbed;
            prevNotRobbed = currNotRobbed;
        }
        return max(prevRobbed, prevNotRobbed);
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution sol;
    int maxMoney = sol.findMaxMoney(nums);
    cout << "The maximum amount of money that can be obtained is: " << maxMoney << endl;
    return 0;
}
