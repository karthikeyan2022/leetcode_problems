/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        if(len < 2) return len;
        
        int gSum = 0;
        
        vector<int> lisSum(len, 1);
        
        for(int i = 1; i < len; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                // strictly increasing i > j
                if(nums[j] < nums[i])
                {
                    lisSum[i] = max(lisSum[i], lisSum[j]+1);
                }
            }
             gSum = max(gSum, lisSum[i]);
        }
        
        // for(int a : lisSum)
        //     cout << a << " ";
        // cout << endl;
        
        return gSum;
    }
};
// @lc code=end

