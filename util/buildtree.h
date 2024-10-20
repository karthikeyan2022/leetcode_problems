#ifndef _BUILDTREE_H__
#define _BUILDTREE_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>

#define NULL_NUM (INT_MIN)
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeFromFile(char* pcFileName);
#endif // _BUILDTREE_H__