/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
         //  int index = -1;
        
        int pivotidx = -1;
        int len = nums.size();
      
        if(len == 1) {
            if(nums[0] == target) return 0;
            else return -1;
        }
        // find the pivot index using binary search        
        int left = 0;
        int right = len - 1;
     
        int mid = 0;
        
        while(left < right)
        {
            // get mid value
            mid = left + ((right-left)/2);
            
            if(left == mid)
            {
                pivotidx = right;
                break;
            }
            // pivot is in right half
            if(nums[left] < nums[mid])
            {
                left = mid;
            }
            else // pivot is in left half
            { 
                right = mid;
            }
        }
        
        //cout << pivotidx << endl;
        
        // choose where to perform bin search (array left to pivot <or> array right to pivot)
        if( nums[0] <= target && target <= nums[pivotidx-1])
        {
            left = 0;
            right = pivotidx-1;          
        }
        else if ( nums[pivotidx] <= target && target <= nums[len-1])
        {
            left = pivotidx;
            right = len-1;
        }
        else
        {
            // out of range
            return -1;
        }
        
        //cout << left << right << endl;
        
        while(left <= right)
        {
            // get mid value
            mid = left + ((right-left)/2);
            
            if(nums[mid] == target) 
            {
                return (mid);
            }
            
            if(left == right) break;
            
            
            // target is in left half
            if(target < nums[mid])
            {
                right = mid-1;
            }
            else // target is in right half
            { 
                left = mid+1;
            }
        }
        
        
        
        return -1;
    }
};
// @lc code=end

