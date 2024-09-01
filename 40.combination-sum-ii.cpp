/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:

    int len;
    vector<vector<int>> retVect;
    int TARGET = 0;
    void checkTargetSum(int locsum, vector<int>& candidates, vector<int>& nums, int idx)
    {
        if(locsum >= TARGET)
        {
            // push and return
            if(locsum == TARGET)
            {
                retVect.push_back(nums);
            }
            return;
        }

        for(int i = idx+1; i < len; i++)
        {
            if(i != idx+1 && candidates[i] == candidates[i-1])
                continue;
                
            nums.push_back(candidates[i]);
            checkTargetSum(locsum + candidates[i], candidates, nums, i);
            nums.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        len = candidates.size();
        temp.clear();
        TARGET = target;
        sort(candidates.begin(), candidates.end() /*, greater<int>()*/);
        
        for(int i = 0; i < len; i++)
        {
            if(i != 0 && candidates[i] == candidates[i-1])
                continue;

            temp.push_back(candidates[i]);
            checkTargetSum(candidates[i], candidates, temp, i);
            temp.pop_back();
        }

        return retVect;
    }
};
// @lc code=end

