/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

#define MODE   0

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

#if(MODE)
        int retVal = 0;    
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        
        retVal = 1;
        
        for(int i = 0; i < len; i++)
        {
            if(nums[i] <= 0) continue;
            
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            if(nums[i] != retVal)
            {
                return retVal;
            }
            else
            {
                retVal = nums[i]+1;
            }
            
        }
        
        return retVal;
#else

        int len = nums.size();
        
        // ignore -ve numbers
        // arrange the positive integers in range [1..n]
        for(int i = 0; i < len; i++)
        {
            // while loop is to swap till all values are in correct position 
            // otherwise already swapped values dont get chance to modified
            while( nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i])
            {
                swap(nums[i], nums[nums[i]-1]);
            }

        }

        // for(int a: nums)
        //     cout << a << " ";
        // cout << endl;

        for(int i = 0; i < len; i++)
        {
            //if(nums[i] <= 0) continue;
            if(nums[i] != (i+1))
            {
                return i+1;
            }
        }
        return len+1;

#endif
    }
};
// @lc code=end

