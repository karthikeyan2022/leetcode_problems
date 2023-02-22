/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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

    int GetMaxDepthRecur(TreeNode* node)
    {
        int nRetVal = 0;
        // If current node is valid, increment '1'
        if(node)
        {
            nRetVal = max(1 + GetMaxDepthRecur(node->left), 
                          1 + GetMaxDepthRecur(node->right));

            return nRetVal;
        }

        return 0;
    }

    int GetMaxDiameter(TreeNode* node)
    {
        int nDepth = 0;
        int nDiameter = 0;
        if(node)
        {
            nDepth = GetMaxDepthRecur(node->left) + GetMaxDepthRecur(node->right);
    
            nDiameter = max(GetMaxDiameter(node->left), GetMaxDiameter(node->right));
        }
        
        return max(nDepth, nDiameter);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return GetMaxDiameter(root);
    }
};
// @lc code=end

