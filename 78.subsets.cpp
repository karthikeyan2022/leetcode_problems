/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

#define DEBUG 0
#define MODE 1

#if(DEBUG)
#include <iostream>
#include <vector>
#include "parse.h"
using namespace std;
#endif

class Solution {
public:

#if(MODE==1)
    // output : include -- not include recursiong
    // [[1,2,3,4],[1,2,3],[1,2,4],[1,2],[1,3,4],[1,3],[1,4],[1],[2,3,4],[2,3],[2,4],[2],[3,4],[3],[4],[]]
    vector<vector<int>> retVal;
    void doRecur(int idx, vector<int>& nums, vector<int>& temp)
    {
        if(idx == nums.size()) {
            retVal.push_back(temp);
            return;
        }
        // include this idx
        temp.push_back(nums[idx]);
        doRecur(idx+1, nums, temp);
        temp.pop_back();

        // not include this idx
        doRecur(idx+1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        doRecur(0, nums, temp);
        return retVal;
    }

#else
    // output - level wise traverse recursion
    // [[],[1],[2],[3],[4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4],[1,2,3],[1,2,4],[1,3,4],[2,3,4],[1,2,3,4]]
    vector<vector<int>> retVect;
    int gLen = 0;
    int gCount = 0;
    

    void doRecursive(int idx, int count, vector<int>& temp, vector<int>& nums)
    {   
        if(count == gCount) {
            retVect.push_back(temp);
            return;
        }
        
        for(int i = idx+1; i < nums.size(); i++) {   
            temp.push_back(nums[i]);
            doRecursive(i, count+1, temp, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        retVect.clear();
        vector<int> temp;
        gLen = nums.size();
        
        vector<int> dummy; 
        retVect.push_back(dummy);
        
        for(int c = 0; c <= nums.size(); c++)
        {
            gCount = c;

            for(int i = 0; i < nums.size(); i++) {
                temp.push_back(nums[i]);
                doRecursive(i, 0, temp, nums);
                temp.pop_back();
            }
        }
        
        return retVect;
    }
#endif
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<int> nums = {1,2,3,4};

    vector<vector<int>> retVal = sol->subsets(nums);

    for(vector<int> nums : retVal)
    {
        printVector(nums);
    }
}

#endif
// @lc code=end

