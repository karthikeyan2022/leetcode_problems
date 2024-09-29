/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#define DEBUG 1
#if(DEBUG)
#include<iostream>
#include<vector>
using namespace std;
#endif

class Solution {
public:

    vector<vector<int>> retVal;
    int g_target = 0;
    void doRecursive(int idx, int sum, vector<int>& temp, vector<int>& nums)
    {   
        if(sum >= g_target) {
            
            if(sum == g_target)
                retVal.push_back(temp);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++) {   
            temp.push_back(nums[i]);
            doRecursive(i, sum+nums[i], temp, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        g_target = target;
        
        vector<int> temp;
        for(int i = 0; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            doRecursive(i, candidates[i], temp, candidates);
            temp.pop_back();
        }

        return retVal;
    }
};

#if(1)
int main()
{
    class Solution* sol = new Solution();

    vector<int> nums = {2,3,6,7};

    vector<vector<int>> retVal = sol->combinationSum(nums, 7);
}
#endif
// @lc code=end

