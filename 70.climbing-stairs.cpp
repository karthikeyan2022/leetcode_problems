/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n < 4) return n;
             
        vector<int> steps(n+1,0);
        
        for(int i = 0; i < 4; i++)
            steps[i] = i;
        
        for(int i = 4; i <= n; i++)
        {
            steps[i] = steps[i-1] + steps[i-2];
        }
        
        return steps[n];
    }
};
// @lc code=end

