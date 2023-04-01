class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set<int> c;
        for (int num : nums1) {
            if (find(nums2.begin(), nums2.end(), num) != nums2.end()) {
                c.insert(num);
            }
        }
        if (!c.empty()) {
            return *c.begin();
        } else {
            int digit1 = *min_element(nums1.begin(), nums1.end());
            int digit2 = *min_element(nums2.begin(), nums2.end());
            if (digit1 < digit2) {
                return digit1 * 10 + digit2;
            } else {
                return digit2 * 10 + digit1;
            }
        }
    }
};
