/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:

    bool isPowerof2(int num)
    {   
        return ((num & (num-1)) == 0);
 #if(0)       
        while(num > 2)
        {
            if(num % 2) return false;
            
            //num = num/2;  
              num = num >> 1;       
        }
        return true;
#endif    
    }

    vector<int> countBits(int n) {
        
        vector<int> retVect(n+1);
        
        if(n == 0) return retVect;
        if(n == 1) {retVect[1] = 1; return retVect;}
        
        retVect[1] = 1;
        retVect[2] = 1;
        int lastPower = 2;
        
        for(int i = 3; i <= n; i++)
        {  
            if( i % 2 == 0 && isPowerof2(i))
            { 
                retVect[i] = 1;
                lastPower = i;
            }
            else
            {
                retVect[i] = 1 + retVect[i - lastPower];
            }
        }
        
        return retVect;
    }
};
// @lc code=end

