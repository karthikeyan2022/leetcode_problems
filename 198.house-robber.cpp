/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start

#define RECUR       0
#define DP          1
#define MODE        (1)

#define MAX_N   102

class Solution {
public:

    int gsum = 0;
    int length = 0;

#if(MODE == RECUR)
    void doRecursive(bool inc, int idx, int sum, vector<int>& nums)
    {
        // out of bound index
        if(idx == length)
        {
            if(sum > gsum)
            {
                gsum = sum;
            }
            return;
        }

        if(!inc)
        {
            doRecursive(1, idx+1, sum+nums[idx],nums);
            doRecursive(0, idx+1, sum, nums);
        }
        else // include case.. so pass 0 to not include in next call
        {
            doRecursive(0, idx+1, sum, nums);
        }
    }
#endif

    int rob(vector<int>& nums) {

        length = nums.size();
        gsum = 0;

        if(length == 1) return nums[0];

        if(length == 2)
        {
            return (nums[0] > nums[1]) ? nums[0] : nums[1];
        }

 #if(MODE == DP)     
        int maxsum[MAX_N];
   
        maxsum[0] = nums[0];
        maxsum[1] = nums[1];
        
        // start loop from idx 2.. get the max of i-2 and i-3 and update maxsum
        for(int i = 2; i < length; i++)
        {
            int max1 = maxsum[i-2]+nums[i];

            int max2 = 0;
            if(i-3 >= 0)
                max2 = maxsum[i-3]+nums[i];

            maxsum[i] = (max1 > max2) ? max1 : max2;

        }

        // finally return maxsum of last and one from last idx
        return (maxsum[length-1]> maxsum[length-2]) ? maxsum[length-1] : maxsum[length-2];        

#elif(MODE == RECUR)  
        // recursive mode gives TLE
        doRecursive(0, 0, 0, nums);

        return gsum;
#endif
        
    }
};
// @lc code=end

