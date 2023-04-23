#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int left = 0, right = 0;
    int max_len = 0;
    while(right < s.size()){
        char c = s[right];
        if(map.count(c) && map[c] >= left){
            left = map[c] + 1;
        }
        map[c] = right;
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}
