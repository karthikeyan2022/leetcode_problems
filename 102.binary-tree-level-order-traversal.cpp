/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start

#define DEBUG   1

#if(DEBUG)
#include "buildtree.h"
#include "parse.h"
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
int main(int argc, char *argv[])
{
    TreeNode* root = buildTreeFromFile(argv[0]);

    if(root == 0)
    {
        return -1;
    }

    class Solution* sol = new Solution();
    
    vector<vector<int>> retVect = sol->levelOrder(root);

    for(vector<int> nums : retVect)
    { 
        printVector(nums);
    }
    
    delete sol;  

    return 0;  
}
#endif
// @lc code=end

