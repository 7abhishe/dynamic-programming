#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    
    if (m == 0) {
        return 0;
    }
    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i+j] == needle[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    // Example usage
    string haystack = "hello";
    string needle = "ll";
    int result = strStr(haystack, needle);
    cout << "Result: " << result << endl;

    return 0;
}
