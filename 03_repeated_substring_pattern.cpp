/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

Example 1:

Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:

Input: "aba"
Output: False

Example 3:

Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/



class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string substring;
        substring += s[0];
        int n = s.length();
        // cout << "\n";
        for (int i=1; i<n; ++i) {
            if (s[i] == substring[0]) {
                bool pattern = true;
                int len = substring.length();
                for (int j=i; j<n; j+=len) {
                    // cout << s.substr(j, len) << " ";
                    if (s.substr(j, len) != substring) {
                        pattern = false;
                        break;
                    }
                }
                if (pattern)
                    return true;
            }
            substring += s[i];
        }
        return false;
    }
};
