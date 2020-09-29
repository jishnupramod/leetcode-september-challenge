/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/



class Solution {
private:
    map<pair<string, string>, bool> dp;
public:
    bool wordBreak(string s, vector<string>& wordDict, string txt = "") {
        if (s.length() == 0) return true;
        if (dp.find({s, txt}) != dp.end()) return dp[{s, txt}];
        for (int i=0; i<s.length(); ++i) {
            txt += s[i];
            if (find(wordDict.begin(), wordDict.end(), txt) != wordDict.end()) {
                dp[{s, txt}] = wordBreak(s.substr(i+1), wordDict, "") or wordBreak(s.substr(i+1), wordDict, txt);
                return dp[{s, txt}];
            }
        }
        return false;
    }
};
