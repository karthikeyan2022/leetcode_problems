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
class Solution {
public:

    int maxval = 0;

    void doRecursive(TreeNode* node, int currval)
    {
        if(node == nullptr)
        {
            if(currval-1 > maxval)
            {
                maxval = currval - 1;
            }
            return;
        }

        doRecursive(node->left, currval+1);
        doRecursive(node->right, currval+1);
    }
    int maxDepth(TreeNode* root) {
        

        doRecursive(root, 1);

        return maxval;
    }
};
// @lc code=end

