/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/



class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {
        int n = v.size();
        vector<vector<int>> merged;
        vector<int> newInt(2);
        bool notMerged = true;
        for (int i=0; i<n; ++i) {
            if (notMerged and newInterval[0] <= v[i][1]) {
                newInt[0] = min(newInterval[0], v[i][0]);
                while (i<n and v[i][0] <= newInterval[1]) {
                    newInt[1] = max(v[i][1], newInterval[1]);
                    ++i;
                }
                --i;
                if (!newInt[1])
                    newInt[1] = newInterval[1];
                merged.push_back(newInt);
                notMerged = false;
            } else
                merged.push_back(v[i]);
        }
        if (notMerged)
            merged.push_back(newInterval);
        return merged;
    }
};
