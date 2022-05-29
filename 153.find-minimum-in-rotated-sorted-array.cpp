/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        
        if(len == 1) return nums[0];
        if( len == 2) return min(nums[0],nums[1]);
        
        int retVal = 5001;
        
        int left = 0;
        int right = len-1;
        int mid;
        
        // no pivot case
        if(nums[left] < nums[right])
        {
            return nums[left];
        }
        
        while(left < right)
        {
            mid = left + ((right-left)/2);
            
            // pivot pair is found!!!
            if(right-left == 1)
            {
                break;
            }
            
            //find pivot element  
            //1.) left subarray is not pivt since sorted, include mid also to find pivt pair correctly
            if(nums[left] < nums[mid])
            {
                left = mid;
            }
            else // pivot element is present in left subarray, include mid also
            {
                right = mid;
            }
            
        }
        
        retVal = min(nums[left], nums[right]);
        return retVal;
        
    }
};
// @lc code=end

