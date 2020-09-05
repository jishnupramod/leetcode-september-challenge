/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Example 5:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

 

Constraints:

    Each tree has at most 5000 nodes.
    Each node's value is between [-10^5, 10^5].
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorder(vector<int>& nodes, TreeNode* root) {
        if (!root) return;
        inorder(nodes, root->left);
        nodes.push_back(root->val);
        inorder(nodes, root->right);
    }

    vector<int> merge(vector<int> nodes1, vector<int> nodes2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nodes1.size() and j < nodes2.size()) {
            if (nodes1[i] < nodes2[j])
                merged.push_back(nodes1[i++]);
            else
                merged.push_back(nodes2[j++]);
        }
        while (i < nodes1.size())
            merged.push_back(nodes1[i++]);
        while (j < nodes2.size())
            merged.push_back(nodes2[j++]);
        return merged;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nodes1, nodes2;
        inorder(nodes1, root1);
        inorder(nodes2, root2);
        return merge(nodes1, nodes2);
    }
};
