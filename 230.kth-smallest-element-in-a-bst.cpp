/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int K;
    bool done = false;
    vector<int> sortArray;
    void inordertraverse(TreeNode* node)
    {   
        if(done) return;
     
        if(node->left)
        {
            inordertraverse(node->left);
        }
        
        sortArray.push_back(node->val);
        
        if(sortArray.size() > K) { done = true; return; }
        
        if(node->right)
        {
            inordertraverse(node->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        done = false;
       // sortArray.clear();
        inordertraverse(root);
        return sortArray[k-1];
  
    }
};
// @lc code=end

