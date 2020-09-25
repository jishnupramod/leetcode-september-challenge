/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/



class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for (int i : nums)
            snums.push_back(to_string(i));
        sort(begin(snums), end(snums), [&](string a, string b) {
            return a+b > b+a;
        });
        string ans;
        for (string s : snums)
            ans += s;
        return ans[0] == '0' ? "0" : ans;
    }
};
