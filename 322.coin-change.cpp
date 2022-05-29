/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#define DEBUG 0

#if(DEBUG)
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#endif

class Solution {
public:
    int count[10000+1] = {0};
    
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0) return 0;
        
        vector<int> tcoins = coins;
        
        sort(tcoins.begin(), tcoins.end());
        
        if(amount < tcoins.front())
            return -1;
                   
        int len = tcoins.size();
       
        for(int i = 1; i <= amount; i++)
        {
            count[i] = amount+1;
            //cout << "amount: " << i << endl;
            for(int j = 0; j < len; j++)
            {
                // can't make from tcoins anymore
                if(tcoins[j] > i)
                    break;
                     
                count[i] = min(count[i], 1 + count[i-tcoins[j]]); 

                // no need to do quo + rem approach. FAIL
                // include 1 count of element only and rest get from dp array 
                // count[i] = min(count[i], quo + count[rem]); 
                
            }
        }
             
        // for(int i = 1; i <= amount; i++)
        //      cout << i << " " << count[i] << endl;
        // cout << endl;
        
        return (count[amount] == (amount+1)) ? -1: count[amount];
        
    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    //[186,419,83,408]  
    //6249

    vector<int> coins = {186,419,83,408};
    sol->coinChange(coins, 6249);
}
#endif
// @lc code=end

