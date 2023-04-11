// 2390. Removing Stars From a String
// Abhishek kumar coode it 
// 1.4K
// 104
// Companies
// You are given a string s, which contains stars *.

// In one operation, you can:

// Choose a star in s.
// Remove the closest non-star character to its left, as well as remove the star itself.
// Return the string after all stars have been removed.

// Note:

// The input will be generated such that the operation is always possible.
// It can be shown that the resulting string will always be unique.
 

// Example 1:

// Input: s = "leet**cod*e"
// Output: "lecoe"
class Solution {
public:
    string removeStars(string s) {
        stack <char>st;
        for(auto c:s)
        {
            if(c=='*')
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        int i=st.size()-1;
        string ans(st.size(),'*');
        while(!st.empty())
        {
            ans[i--]=st.top();
            st.pop();
        }
        return ans;

        
    }
}; // using stack of this questions

class Solution {
public:
    string removeStars(string s) {
        int j=0;
        for(auto i:s)
        {
            if(i=='*')
            {
                j--;
            }
            else
            {
                s[j++]=i;
            }
        }
        return s.substr(0,j);
        
    }
};o(n) time complexity