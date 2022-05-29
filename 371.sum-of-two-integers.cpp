/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        
        // ^ op will do 1+0=1 and 0+1=1
        // & + << 1 will do carry shift 
  
        //[BUG FIX] OVERFLOW ISSUE int --> long int
        long int c=0; // temp
        // b acts as carry in next loop
        while(b != 0)
        {
            c = a & b;
            a = (a ^ b);

            //b = (c) << 1; // not working
             b = c * 2; 
        }
       // sum = (a^b) + ((a&b) *2);

        return a;
    }
};
// @lc code=end

