/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start

// INVALID max length

#define DEBUG	0

#if(DEBUG)
#include<vector>
#include<iostream>
#include "parse.h"
using namespace std;
#endif


#define MODE    0


#define MAX_LENGTH 100001

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {   
#if(MODE)
    // accepted solution. done by me
        int len = nums.size();
        int minRangeLen = MAX_LENGTH;
        int sum = 0;
        for(int i = 0; i < len; i++)
        {   
            sum = nums[i];

            // if one entry itself sums to target
            if(sum >= target)
            {
                minRangeLen = min(minRangeLen, 1);
                break;
            }

            for(int j = i+1; j < len; j++)
            {
                sum += nums[j];

                if(sum >= target)
                {
                    minRangeLen = min(minRangeLen, j-i+1);
                    break;
                }
            }
        }

        return (minRangeLen == MAX_LENGTH) ? 0 : minRangeLen;
#else
        // proper sliding window
        int len = nums.size();
        int minRangeLen = MAX_LENGTH;
        int leftp = 0;

        // i is the rightp
        for(int i = 0; i < len; i++)
        {
            // decrement value from target;
            target -= nums[i];


            // if target reaches <= 0, then make it to reach above 0
            // also the min range is reached. track it
            while(target <= 0)
            {
                minRangeLen = min(minRangeLen, i - leftp +1);
                
                // move right the sliding window
                target += nums[leftp];
                leftp++;
            }


        }

       return (minRangeLen == MAX_LENGTH) ? 0 : minRangeLen;


#endif
    }   
};


#if(DEBUG)
/*
 * Main static function 

 
 */
int main()
{
    class Solution* sol = new Solution();

    vector<int> arr = {2,3,1,2,4,3};

    sol->minSubArrayLen(7, arr);


}
#endif
// @lc code=end

