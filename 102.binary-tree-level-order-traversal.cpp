/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start

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

    list<TreeNode*> listOfNodes;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> retVect;
        listOfNodes.clear();

        if(root == nullptr) return retVect;

        // push the root treenode into the list first

        listOfNodes.push_back(root);

        while(!listOfNodes.empty())
        {
            // 1.) traverse all nodes in the list and put into ret Vect for a LEVEL
            list<TreeNode*>::iterator it;
            vector<int> tempVect;
            TreeNode* tempNode;
            for(it = listOfNodes.begin(); it != listOfNodes.end(); it++)
            {
                tempNode = *it;
                tempVect.push_back(tempNode->val);
            }
            retVect.push_back(tempVect);

            int popCount = listOfNodes.size();
            
            // pop the previous LEVEL nodes and push their left.right nodes for Next LEVEL
            while(!listOfNodes.empty() && popCount--)
            {
                TreeNode* node = listOfNodes.front();
                listOfNodes.pop_front();

                if(node->left)
                    listOfNodes.push_back(node->left);

                if(node->right)
                    listOfNodes.push_back(node->right);

            }

        }
       
        return retVect;
        
    }
};


#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    debug(5);
    TreeNode* left2 = new TreeNode(15);
    TreeNode* right2 = new TreeNode(7);
    TreeNode* right1 = new TreeNode(20, left2, right2);

    TreeNode* left1 = new TreeNode(9);

    TreeNode* root = new TreeNode(3, left1, right1);
    
    vector<vector<int>> retVect = sol->levelOrder(root);

    delete sol;    
}
#endif
// @lc code=end

