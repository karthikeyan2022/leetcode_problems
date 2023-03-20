/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define DEBUG 0

#if(DEBUG)
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Codec {
public:

    string intToStr(int num)
    {
        string str;

        if(num < 0) {
            str.push_back('-');
            num = -num;
        } else {
            str.push_back('+');
        }

        int x = num;
        int c;

        while(x)
        {
            c = x % 10;
            str.push_back(c);
            x = x / 10;
        }

        int len;
        
        len = 5 - str.size(); // 4 digit + 1 sign

        while(len--)
            str.push_back(0);
        

        return str;
    }

    int strToInt(string str)
    {
        while(str.size() != 5);

        int num = str[1];
        num += (str[2] * 10);
        num += (str[3] * 100);
        num += (str[4] * 1000);

        if(str[0] == '-')
            num = -num;

        return num;
    }

    void createPreorder(TreeNode* node, vector<int>& nums)
    {
        if(node == nullptr) return;
        // root push
        nums.push_back(node->val);

        createPreorder(node->left, nums);

        createPreorder(node->right, nums);
    }

    void createPreorderloc(TreeNode* node, string& str, string sub)
    {
        if(node == nullptr) return;

        str.append(sub);
        str.push_back(';');

        createPreorderloc(node->left, str, sub + "l");

        createPreorderloc(node->right, str, sub + "r");
    }

    string vectorToString(vector<int>& nums)
    {
        string str;

        int len = nums.size();
        int num;
        for(int i = 0; i < len; i++)
        {
            str.append(intToStr(nums[i]));
        }

        return str;
    }

    vector<int> stringToVector(string str)
    {
        int len = str.size();
        vector<int> nums;
        string temp;
        for(int i = 0; i < len; )
        {
            temp = str.substr(i, 5);
            nums.push_back(strToInt(temp));
            i = i + 5;
        }
        return nums;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // create preorder and inorder array
        vector<int> preorder;
        createPreorder(root, preorder);

        string locationstr;
        createPreorderloc(root, locationstr, "");



        //cout << locationstr.length() << endl;
        string prestr = vectorToString(preorder);

        prestr.push_back(':');

        prestr.append(locationstr);
        return prestr;
    }

    TreeNode* retnode;
    void insertToTree(string str, vector<int>& nums, int idx)
    {
        int slen = str.size();
        TreeNode* tnode = retnode;
        for(int i = 0; i < slen; i++)
        {
            if(str[i] == 'o')
            {
                   // no need at all since 'o' root is redundant 
            }
            else if(str[i] == 'l')
            {
                if(tnode->left)
                {
                    tnode = tnode->left;
                }
                else {
                    tnode->left = new TreeNode(nums[idx]);
                    //cout << nums[idx] << " ";
                    return;
                }
            }
            else if(str[i] == 'r')
            {
                if(tnode->right)
                {
                    tnode = tnode->right;
                }
                else {
                    tnode->right = new TreeNode(nums[idx]);
                    //cout << nums[idx] << " ";
                    return;
                }
            }
        }

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        
        // Find position of ':' using find()
        int pos = data.find(":");
 
        string prestr = data.substr(0, pos);
        vector<int> preorder = stringToVector(prestr);
        
        string locationstr = data.substr(pos+1);

        int len = preorder.size();

        int idx = 0;
        string temp;
        retnode = 0;
        if(len <= 0)
            return 0;
        else
        {
            retnode = new TreeNode(preorder[0]);
        }

        idx = 1;
        for(int i = 1; i < len; i++)
        {
            temp;
            while(locationstr[idx] != ';')
            {
                temp.push_back(locationstr[idx]);
                idx++;
            }
            idx++;

            insertToTree(temp, preorder, i);
            
            //cout << "root: " << root->val << endl;
            temp.clear();
        }

        return retnode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
#if(DEBUG)
int main()
{
    Codec ser, deser;

    TreeNode* root = new TreeNode(100);
    TreeNode* ans = deser.deserialize(ser.serialize(root));

}
#endif
// @lc code=end

