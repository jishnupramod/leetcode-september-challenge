/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

    All numbers will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/



class Solution {
private:
    void genCombs(int i, int index, vector<int>& c, vector<vector<int>>& combs, int n, int k) {
        if (index == k and n == 0) {
            combs.push_back(c);
            return;
        }
        if (n < 0 or index >= k or i > 9) return;
        c[index] = i;
        genCombs(i+1, index+1, c, combs, n-i, k);
        genCombs(i+1, index, c, combs, n, k);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combs;
        vector<int> comb(k);
        genCombs(1, 0, comb, combs, n, k);
        return combs;
    }
};
