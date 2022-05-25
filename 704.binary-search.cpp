/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
     
        int left = 0;
        int right = nums.size() -1;

        int mid;

        while(left <= right)
        {
            mid = left + (right-left)/2;

            if(nums[mid] == target)
            {
                return mid;
            }

            if(target < nums[mid])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            } 
        }

        return -1;     
    }
};
// @lc code=end

