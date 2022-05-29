/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int prevMin = 100001;
        
        int len = prices.size();
        
        if(len < 2) return 0;
        
        prevMin = prices[0];
        
        for(int i = 1; i < len; i++)
        {
            profit = max(profit, prices[i]- prevMin);
            
            prevMin = min(prevMin, prices[i]);
        }
                         
        return profit;
    }
};
// @lc code=end

