/*
Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"

Example 2:

Input: [5,5,5,5]
Output: ""

 

Note:

    A.length == 4
    0 <= A[i] <= 9
*/



class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string time;
        int mx_time = 0, z = 0;
        for (int i : A) {
            if (i == 0)
                ++z;
        }
        if (z == 4)
            return "00:00";
        sort(A.begin(), A.end());
        do {
            int t = 0;
            for (int i : A)
                t = t * 10 + i;
            int mts = t / 100;
            if (t % 100 < 60 and mts < 24)
                mx_time = max(mx_time, t);
        } while (next_permutation(A.begin(), A.end()));
        if (mx_time == 0)
            return "";
        string stime = to_string(mx_time);
        if (mx_time < 1000)
            time = '0' + stime.substr(0, 1) + ':' + stime.substr(1);
        else
            time = stime.substr(0, 2) + ':' + stime.substr(2);
        return time;
    }
};
