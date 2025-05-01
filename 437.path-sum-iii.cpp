/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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

#define DEBUG 1
#if(DEBUG)
#include "buildtree.h"
#include "parse.h"
using namespace std;
#endif

class Solution {
public:

    int count = 0;
    void doRecur(TreeNode* node, int targetSum, int curr_sum)
    {

        //if(node->left == 0 && node->right == 0)
        {
            cout << curr_sum << endl;
            if(curr_sum == targetSum)
            {
                count++;
                return;
            }
          
        }

        if(node->left)
            doRecur(node->left, targetSum, curr_sum + node->left->val);

        if(node->right)
            doRecur(node->right, targetSum, curr_sum + node->right->val);

        if(node->left)
            doRecur(node->left, targetSum, node->left->val);

        if(node->right)
            doRecur(node->right, targetSum, node->right->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == 0)
            return 0;

        
        doRecur(root, targetSum, root->val);

        return count;
    }
};

#if(DEBUG)
int main(int argc, char *argv[])
{
    TreeNode* root = buildTreeFromFile(argv[0]);

    if(root == 0)
    {
        return -1;
    }

    class Solution* sol = new Solution();
    
    int cocunt = sol->pathSum(root, 3);

   
    
    delete sol;  

    return 0;  
}
#endif
// @lc code=end

