/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = INT_MIN, cand2 = INT_MIN, cnt1 = 0, cnt2 = 0, n = nums.size();
        for (int i : nums) {
            if (i == cand1)
                ++cnt1;
            else if (i == cand2)
                ++cnt2;
            else if (cnt1 == 0) {
                cand1 = i;
                ++cnt1;
            }
            else if (cnt2 == 0) {
                cand2 = i;
                ++cnt2;
            }
            else {
                --cnt1;
                --cnt2;
            }
        }
        vector<int> major;
        cnt1 = cnt2 = 0;
        for (int i : nums) {
            if (i == cand1) ++cnt1;
            if (i == cand2) ++cnt2;
        }
        if (cnt1 > n/3)
            major.push_back(cand1);
        if (cnt2 > n/3 and cand2 != cand1)
            major.push_back(cand2);
        return major;
    }
};
