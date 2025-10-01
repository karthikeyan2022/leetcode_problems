/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:

    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int count = 0;
    vector<vector<int>> retVal;
    void doRecur(int idx, int level, int curr_sum, int sum, int tot_level, vector<int>& temp)
    {
        if (level >= tot_level)
        {
            //cout << "level: " << level << " Curr_sum: " << curr_sum << endl;
            if ((level == tot_level) && (curr_sum == sum))
            {
                retVal.push_back(temp);
                count++;
            }
            return;
        }

        if(curr_sum > sum)
        {
            return;
        }

        // do recur two ways
        // include sum
        // dont include sum
        if(idx == nums.size())
            return;

        temp.push_back(nums[idx]);
        doRecur(idx+1, level+1, curr_sum+nums[idx], sum, tot_level, temp);
        temp.pop_back();
        doRecur(idx+1, level, curr_sum, sum, tot_level, temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> temp;

        doRecur(0, 0, 0, n, k, temp);
        cout << "Count: " << count << endl;
        return retVal;
    }
};

int main()
{
    class Solution* sol = new Solution();

    vector<vector<int>> retVal = sol->combinationSum3(3, 7);
}
// @lc code=end

