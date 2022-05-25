/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int len = nums.size();
        //vector<int> sums(len, INT_MIN);
        int localsum = INT_MIN;
        
        for(int i = 0; i < len; i++)
        {
            if(i == 0)
            {
                maxsum = max(maxsum, nums[i]);
                localsum = maxsum;
                continue;
            }
            
            // prev sum + curr no. (OR) curr no. only
            localsum = max(localsum+nums[i], nums[i]);
            maxsum = max(maxsum, localsum);
           
        }
        
        return maxsum;
        
    }
};
// @lc code=end

