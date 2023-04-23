#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left + 1;
    int j = right;
    
    while (i <= j) {
        if (nums[i] <= pivot) {
            i++;
        } else if (nums[j] > pivot) {
            j--;
        } else {
            swap(nums[i], nums[j]);
        }
    }
    
    swap(nums[left], nums[j]);
    
    return j;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int pivotIndex = partition(nums, left, right);
    quickSort(nums, left, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, right);
}

int main() {
    // Example usage
    vector<int> nums = {4, 1, 3, 8, 5};
    quickSort(nums, 0, nums.size() - 1);
    
    // Print sorted array
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
