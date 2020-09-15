/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/


// Init Solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        string last, temp;
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == ' ' and !temp.empty()) {
                last = temp;
                temp = "";
            } else if (s[i] != ' ')
                temp += s[i];
        }
        if (!temp.empty()) last = temp;
        return last.length();
    }
};



// Alternative Solution
class Solution {
public:
    int lengthOfLastWord(string s) {
        auto l = s.begin(), r = s.end()-1;
        int res = 0;
        while ((*l) == ' ') ++l;
        while ((*r) == ' ') --r;
        while (l <= r) {
            if ((*l) == ' ')
                res = 0;
            else
                ++res;
            ++l;
        }
        return res;
    }
};

