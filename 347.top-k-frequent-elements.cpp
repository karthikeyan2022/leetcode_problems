/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
struct node
{
    int num;
    int count;
};

struct compare
{
    // return true if count of node1 is less than node2's count 
    // node of larger count comes 'last' meaning front of the queue
    bool operator() (node* const& node1, node* const& node2)
    {
        return ((node1->count) < (node2->count)) ? true : false;
    }
};


class Solution {
public:
    
    unordered_map<int, int> count_hash;
    priority_queue <node*, vector<node*>, compare> nodeHeap;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> retVect;
        for(int i = 0; i < nums.size(); i++)
        {
            count_hash[nums[i]]++;
        }
        
        for(auto entry: count_hash)
        {
            node* nnode = new node();
            nnode->num = entry.first;
            nnode->count = entry.second;
            nodeHeap.push(nnode);
        }
           
        while(k-- && !nodeHeap.empty())
        {
            struct node* popnode = nodeHeap.top();
            nodeHeap.pop();
            retVect.push_back(popnode->num);
        }
        
        return retVect;
    }
};
// @lc code=end

