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
        vector<int> left_prod(len);
        vector<int> right_prod(len);
        vector<int> result(len);
        
        left_prod[0] = 1; // dummy
        
        // do for 2nd to last
        for(int i = 1; i < len; i++)
        {
            left_prod[i] = nums[i-1]*left_prod[i-1];                           
        }
        
        right_prod[len-1] = 1; //dummy
        
        // do for 2nd from last to first
        for(int i = len-2; i >=0; i--)
        {
            right_prod[i] = nums[i+1]*right_prod[i+1];          
        }
        
        // make the result
        for(int i = 0; i < len; i++)
            result[i] = left_prod[i]*right_prod[i];
       
        return result;
    }
};
// @lc code=end

