#include <iostream>
#include <vector>
using namespace std;

vector<int> separateDigits(vector<int>& nums) {
    int n = nums.size();
    vector<int> counts(10, 0); // Initialize a count array for digits 0-9
    for(int i=0;i<n;i++){
        int num = nums[i];
        while(num > 0){ // Loop to extract each digit from the current number
            int digit = num % 10;
            counts[digit]++;
            num /= 10;
        }
    }
    vector<int> result; // Initialize a result array for the separated digits
    for(int i=0;i<=9;i++){ // Loop to add each digit to the result array the corresponding number of times
        for(int j=0;j<counts[i];j++){
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {123, 3, 45, 6, 583}; // Example input
    vector<int> digits = separateDigits(nums);
    cout << "Separated digits: ";
    for(int i=0;i<digits.size();i++){
        cout << digits[i] << " ";
    }
    cout << endl;
    return 0;
}
