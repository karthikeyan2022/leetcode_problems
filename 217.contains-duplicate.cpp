/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start

#define DEBUG 1

#if(DEBUG)
#include <vector>
#include <unordered_set>
using namespace std;
#endif



class Solution {
public:
    
    //unordered_map<int, bool> hash;
    unordered_set<int> simplehash;
    unordered_set<int> :: iterator itr;
    
    bool containsDuplicate(vector<int>& nums) {
        
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            // get the itr as result of finding the entry
            itr = simplehash.find(nums[i]);

            // if the entry is already present
            if(itr != simplehash.end())
            {
                   return true;
            }
            
            // add the entry to the set
            simplehash.insert(nums[i]);
        }
        return false;
    }
};

#if(DEBUG)
int main()
{
    Solution* sol = new Solution();

    vector<int> nums;
    nums.push_back(1);

    sol->containsDuplicate(nums);    
}
#endif
// @lc code=end

