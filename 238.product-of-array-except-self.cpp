/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int len = nums.size();
        vector<int> prefix(len);
        vector<int> result(len);
        
        result[0] = 1;
        prefix[0] = nums[0];
        
        for(int i = 1; i < len; i++)
        {
            prefix[i] = nums[i]*prefix[i-1];         
            result[i] = prefix[i-1];                        
        }
        
        prefix[len-1] = nums[len-1];
        for(int i = len-2; i >=0; i--)
        {
            prefix[i] = nums[i]*prefix[i+1];
                     
            result[i] *= prefix[i+1];             
        }
        
       
        return result;
    }
};
// @lc code=end

