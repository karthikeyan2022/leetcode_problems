/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int retVal = 0;
        
        int len = nums.size();
        
        if(len < 2) return len;
        
        vector<int> count(nums);
        // for(int a : nums)
        // {
        //     count.push_back(a);
        // }
        
        // for(int a: count)
        //     cout << a << " ";
        
        sort(count.begin(), count.end());
        
        int locCount = 1;
        retVal = max(retVal, locCount);
        for(int i = 1; i < len; i++)
        {
            if(count[i-1] == count[i]) continue;
            
            if((count[i] - count[i-1]) == 1 )
            {
                locCount++;    
            }
            else
            {
                locCount = 1;
            }
            
            retVal = max(retVal, locCount);
        }

        return retVal;
    }
};
// @lc code=end

