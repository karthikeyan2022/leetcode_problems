/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

#define DEBUG   0

#if(DEBUG)
#include "parse.h"
using namespace std;
#endif

// recursion method with memoization
        /*
           /\
          /  \
         (-1) (+1)
        */


 #define MAX_LEN    20
 #define MAX_SUM    1001   

class Solution {
public:

    int _target = 0;
    int _length = 0;
    int _total = 0; //acts as offset since range is - total to 0,  + total
    int countarr[MAX_LEN][2*MAX_SUM + 1];

    int doRecursive(vector<int> nums, int idx, int sum)
    {

        if(idx == _length)
        {
            if(_target == sum)
                return 1;
            else
                return 0;
        }

        // already memoized
        if(countarr[idx][sum+_total] != -1)
        {
             return countarr[idx][sum+_total];   
        }
        else  // calcualte and memoize it
        {

            int add = doRecursive(nums, idx+1, sum+nums[idx]);
            int sub = doRecursive(nums, idx+1, sum-nums[idx]);

            countarr[idx][sum+_total] = add + sub;
        
            return countarr[idx][sum+_total];
        
        }

        // wont come here ever!!!
        return -1;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        _target = target;
        _length = nums.size();


        _total = 0;      
        for(int i = 0; i < _length; i++) {_total += nums[i];}
       // memset(countarr, -1, sizeof(*countarr)*_length*(2*_total+1));

        
        for(int i = 0; i < _length; i++)
        {
            for(int j = 0; j < (2*_total+1); j++)
            {
                countarr[i][j] = -1;
            }
        }

        return doRecursive(nums, 0, 0);

    }
};


#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<int> nums = {1,0};

    sol->findTargetSumWays(nums,1);


    delete sol;
}
#endif
// @lc code=end

