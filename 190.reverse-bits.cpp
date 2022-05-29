/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       
       int c = 32 /2;     
       uint32_t retVal = 0;
        
       for(int i = 0; i <= c; i++)
       {
           int j = 31 - i;
           
           int num1 = (n >> i) & 1;
           int num2 = (n >> j) & 1;
           
           retVal = retVal | (num2 << i);
           retVal = retVal | (num1 << j);
        }
        
        return retVal;
    }
};
// @lc code=end

