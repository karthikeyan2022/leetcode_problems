/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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

list<TreeNode*> listOfNodes;
vector<vector<int>> retVect;

class Solution {
public:  
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        listOfNodes.clear();
        retVect.clear();

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

        
        // reverse the elements (vector<int>) in retVect
        // vector<vector<int>> actualretVect; 
       
        // while(!retVect.empty())
        // {
        //     vector<int> tempVect = retVect.back();
        //     retVect.pop_back();

        //     actualretVect.push_back(tempVect);
        // }
        
        reverse(retVect.begin(), retVect.end());
        return retVect;
        
    }
};


#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();


    TreeNode* left2 = new TreeNode(15);
    TreeNode* right2 = new TreeNode(7);
    TreeNode* right1 = new TreeNode(20, left2, right2);

    TreeNode* left1 = new TreeNode(9);

    TreeNode* root = new TreeNode(3, left1, right1);
    
    vector<vector<int>> retVect = sol->levelOrderBottom(root);

    delete sol;    
}
#endif
// @lc code=end

