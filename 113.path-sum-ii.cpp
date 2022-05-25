/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    
    int gtarget = 0;
    vector<vector<int>> retVect;
    void doRecursive(TreeNode* currNode, list<TreeNode*> ll, int currSum)
    {
        if(currNode == 0) return;
        
        //cout << currNode->val << " :";
        //list<TreeNode*>:: iterator it;
                
        //for(it = ll.begin(); it != ll.end(); it++)
       // {
        //    TreeNode* node = *it;
        //    cout << node->val << " ";
        //}
        //cout << endl;
        
        // if this node is leaf node
        if(currNode->left == 0 && currNode->right == 0)
        {
            //cout << currSum << " leaf node" << endl;
            if((currSum + currNode->val) == gtarget)
            {
                //cout << " path found" << endl;
                vector<int> temp;
                list<TreeNode*>:: iterator it;
                
                for(it = ll.begin(); it != ll.end(); it++)
                {
                    TreeNode* node = *it;
                    temp.push_back(node->val);
                }
                retVect.push_back(temp);
                
            }    
            return;
        }
        
        // wont work since negative numbers also can be present
        // if(currSum+currNode->val > gtarget)
        //     return;
        
        if(currNode->left)
        {
            ll.push_back(currNode->left);
            doRecursive(currNode->left, ll, currSum+currNode->val);
            ll.pop_back();
        }
        
        if(currNode->right)
        {
            ll.push_back(currNode->right);
            doRecursive(currNode->right, ll, currSum+currNode->val);
            ll.pop_back();
        }
        
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        retVect.clear();
        list<TreeNode*> ll;
        gtarget = targetSum;
        if(root == 0) return retVect;
        
        ll.push_back(root);
        doRecursive(root, ll, 0);
        
        return retVect;
    }
};
// @lc code=end

