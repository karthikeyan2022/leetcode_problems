/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
         int c = 32;
        
        int count = 0;
        while(c--)
        {
            count += ((n >> c) & 1);
        }
        
        return count;
    }
};
// @lc code=end

