/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int c1 = 1, c2 = 1, mp = 1, mn = 1, maxProd = INT_MIN;
        for (int i : nums) {
            c1 = mp * i;
            c2 = mn * i;
            mp = max({c1, c2, i});
            mn = min({c1, c2, i});
            maxProd = max(maxProd, mp);
        }
        return maxProd;
    }
};
