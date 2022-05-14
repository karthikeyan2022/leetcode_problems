/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
#define DEBUG   0

#if(DEBUG)
#include "parse.h"
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include <chrono>
using namespace std;
#endif

#define RECUR   0
#define DP      1
#define MODE    DP

#define MAX_SIZE    1002

class Solution {
public:

    unsigned int counter = 0;
    unsigned int _target = 0;
    unsigned int length = 0;

    unsigned int memt[1002];

#if(MODE == RECUR)
    void doRecursive(vector<int>& nums, int curSum)
    {
        // recursive stop cond
        if(curSum == _target)
        {
            counter++;
            return;
        }

        if(curSum > _target)
        {
            return;
        }

        for(int i = 0; i < length; i++)
        {
            doRecursive(nums, curSum+nums[i]);
        }

    }
#endif

    int combinationSum4(vector<int>& nums, int target) {
        
        _target = target;
        counter = 0;
        length = nums.size();

        vector<int> localnums = nums;

        //DP approach dont need sorting for 3loops
        sort(localnums.begin(), localnums.end());
#if(MODE == RECUR)
        
     
        for(int i = 0; i < length; i++)
        {
            doRecursive(localnums, localnums[i]);
        }

        return counter;
#elif(MODE == DP)

        for(int i = 0; i <= target; i++)
        {
            memt[i] = 0;
        }
        memt[0] = 1;
        int idx = 0;

        for(idx = 1; idx <= target; idx++)
        {
            
            for(int i = 0; i < length; i++)
            {
                // optimized approach from comments
                // this makes the 3rd loop redundant
                if(localnums[i] <= idx)
                {
                    memt[idx] += memt[idx-localnums[i]];
                }
                // // starts from 0 due to include own index
                // // 3rd for loop is added after debugging
                // for(int idx2 = 0; idx2 < idx; idx2++)
                // {
                //     // for its and previous index
                //     if(idx == (idx2 + localnums[i]))
                //     {
                //         memt[idx] += memt[idx2];
                //     }
                // }
                
            }
        }

        return memt[target];

#endif


    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<int> nums;

    // for(int i = 3; i > 0; i--)
    //     nums.push_back(i);

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    auto stTime = chrono::steady_clock::now();
    cout << sol->combinationSum4(nums, 32) << endl;
    auto endTime = chrono::steady_clock::now();

    cout << "Elapsed time: "
        << chrono::duration_cast<chrono::milliseconds>(endTime-stTime).count()
        << "ms" << endl;
}
#endif
// @lc code=end

