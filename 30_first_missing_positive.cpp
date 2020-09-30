/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Follow up:

Your algorithm should run in O(n) time and uses constant extra space.
*/



// O(n) Space solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> bkt(n+1);
        for (int i : nums) {
            if (i >= 0 and i <= n)
                bkt[i] = i;
        }
        for (i=0; i<=n; ++i) {
            if (bkt[i] != i)
                break;
        }
        return i;
    }
};
