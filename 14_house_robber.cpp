/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    0 <= nums.length <= 100
    0 <= nums[i] <= 400
*/



class Solution {
private:
    int best = 0;
    int maxRob(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size())
            return 0;
        if (dp[i])
            return dp[i];
        best = max(nums[i]+maxRob(nums, i+2, dp), maxRob(nums, i+1, dp));
        dp[i] = best;
        return best;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if (nums == dp)
            return 0;
        return maxRob(nums, 0, dp);
    }
};
