/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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

#define DEBUG   0

//Definition for a binary tree node.
#if(DEBUG)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif


#if(DEBUG)
#include<iostream>
#include<vector>
#include<list>
using namespace std;
#endif


class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {

        if(root == 0) return root;

        list<TreeNode*> ll;


        ll.push_back(root);

        while(!ll.empty())
        {
            TreeNode* node = ll.front();
            ll.pop_front();

            if(node)
            {
                ll.push_back(node->left);
                ll.push_back(node->right);

                //swap(node->left, node->right);

                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;

            }
        }
     
       return root;      
    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    sol->invertTree(0);
}
#endif
// @lc code=end

