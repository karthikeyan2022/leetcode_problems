/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int a = 0;
        //XOR a number two times gives result as 0.
        // Hence we get a unique single number here.
        for(int x : nums)
        {
            a ^= x;
        }
        return a;
    }
};
// @lc code=end

