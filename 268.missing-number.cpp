/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start

#define MODE 1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
#if(MODE)
        // sum of positive integers      
        //  n / 2 * ( 2a + (n-1)*d)
        
        int n = nums.size(); //10000;
        
        long long unsigned int bignum;
        
        bignum = (n) * (2 + (n-1));
        bignum = bignum/2;
        
       //  cout << bignum << endl;
        
        for(int i = 0; i < n; i++)
        {
            bignum -= nums[i];
        }
        return (int)bignum;
#else
        int res = nums.size();

        for(int i = 0; i < nums.size(); i++){
            res ^= i;
            res ^= nums[i];
        }

        return res;
#endif    
    }
};
// @lc code=end

