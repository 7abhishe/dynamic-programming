// 20. Valid Parentheses
// Abhishek-kumar solved these questions
// 19.2K
// 1.1K
// Companies
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false


bool isValid(string s) {
        string st;
        map<char,char>mp;
        mp['(']=')';
        mp['{']='}';
        mp['[']=']';
        st.push_back(s[0]);
          for (int i = 1; i < s.size(); i++) {
            if(mp[st.back()] == s[i])
                st.pop_back();
            else
                st.push_back(s[i]);
        }
        return st.size() ? 0 : 1;
        
    }