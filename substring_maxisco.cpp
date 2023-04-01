class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
            // create dictionary of char values
    unordered_map<char, int> char_vals;
    for (int i = 0; i < chars.length(); i++) {
        char_vals[chars[i]] = vals[i];
    }

    // initialize variables
    int max_sum = 0;
    int cur_sum = 0;

    // traverse through string
    for (char c : s) {
        if (char_vals.find(c) != char_vals.end()) {
            cur_sum += char_vals[c];
        }
        else {
            cur_sum += c - 'a' + 1;
        }
        if (cur_sum < 0) {
            cur_sum = 0;
        }
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
    }

    return max_sum;
        
    }
};