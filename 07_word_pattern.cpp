/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/



class Solution {
private:
    vector<string> tokenize(string str) {
        vector<string> words;
        stringstream ss(str);
        string s;
        while (getline(ss, s, ' '))
            words.push_back(s);
        return words;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        words = tokenize(str);
        if (pattern.length() != words.size())
            return false;
        unordered_map<char, string> mapp;
        unordered_map<string, char> mapp2;
        int i = 0;
        for (char ch : pattern) {
            if (mapp.find(ch) == mapp.end())
                mapp[ch] = words[i];
            else if (mapp[ch] != words[i])
                return false;
            ++i;
        }
        i = 0;
        for (string w : words) {
            if (!mapp2[w])
                mapp2[w] = pattern[i];
            else if (mapp2[w] != pattern[i])
                return false;
            ++i;
        }
        return true;
    }
};
