#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> twoSum(vector<int>& nums, int target, int timeLimit) {
    unordered_map<int, int> map;
    auto startTime = high_resolution_clock::now();
    while(duration_cast<milliseconds>(high_resolution_clock::now() - startTime).count() < timeLimit){
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(map.count(complement)){
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    int timeLimit = 1000; // Time limit in milliseconds
    vector<int> result = twoSum(nums, target, timeLimit);
    if(result.size() > 0){
        for(int i=0;i<result.size();i++){
            cout << result[i] << " ";
        }
    } else {
        cout << "Time limit exceeded" << endl;
    }
    return 0;
}
