/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
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

#define MAXIMUM     max

class Solution {
public:

    int GetMaxDepthRecur(TreeNode* node)
    {
        // If current node is valid, increment '1'
        if(node)
        {
            return MAXIMUM(1 + GetMaxDepthRecur(node->left), 
                           1 + GetMaxDepthRecur(node->right));
        }

        return 0;
    }

    // Functions to implement
    int maxDepth(TreeNode* root) {
        return GetMaxDepthRecur(root);
    }
};
// @lc code=end

