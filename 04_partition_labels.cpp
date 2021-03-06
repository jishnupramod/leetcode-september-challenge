/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

 

Note:

    S will have length in range [1, 500].
    S will consist of lowercase English letters ('a' to 'z') only.
*/



class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> freq, added;
        vector<int> ans;
        for (char ch : S) ++freq[ch];
        string partition;
        bool flag = true;
        for (char ch : S) {
            flag = true;
            partition += ch;
            ++added[ch];
            for (char c : partition) {
                if (added[c] < freq[c]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(partition.length());
                partition = "";
            }
        }
        return ans;
    }
};
