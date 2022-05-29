/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* newnodes[101] = {0};
    bool done[101] = {false};
    
    void dorecursive(Node* node)
    { 
        done[node->val] = true;
        
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            Node* tnode = node->neighbors[i];
            
            if(!newnodes[tnode->val])
                newnodes[tnode->val] = new Node(tnode->val);
            
            newnodes[node->val]->neighbors.push_back(newnodes[tnode->val]);
            
             if(!done[tnode->val])
                dorecursive(tnode);
        }
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node == 0) return 0;
         
        newnodes[node->val] = new Node(node->val);
        
        // pass ref of given node to get its neighbors
        dorecursive(node);
    
        return newnodes[node->val];
        
    }
};
// @lc code=end

