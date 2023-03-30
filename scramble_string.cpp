
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isAnagram(string s1, string s2) {
        int count[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }

    bool solve(string s1,string s2)
    {
        if (s1 == s2) {
            return true;
        }
        if (!isAnagram(s1, s2)) {
            return false;
        }
        int n = s1.size();
        for(int i = 1; i < n; i++)
        {
            if((solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i)))
              || (solve(s1.substr(0,i),s2.substr(n-i)) && solve(s1.substr(i),s2.substr(0,n-i))))
            {
                return true;
            }
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        return solve(s1, s2);
    }
};

int main() {
    Solution sol;
    cout << sol.isScramble("great", "rgeat") << endl;  // 1
    cout << sol.isScramble("abcde", "caebd") << endl;  // 0
    return 0;
}
