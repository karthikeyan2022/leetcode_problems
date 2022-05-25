/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    
    //unordered_map<int, bool> hash;
    unordered_set<int> simplehash;
    unordered_set<int> :: iterator itr;
    
    bool containsDuplicate(vector<int>& nums) {
        
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            itr = simplehash.find(nums[i]);
            if(itr != simplehash.end())
            {
                   return true;
            }
            
            simplehash.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end

