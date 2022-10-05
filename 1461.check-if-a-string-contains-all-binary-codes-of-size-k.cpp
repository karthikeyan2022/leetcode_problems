/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start

#define MAX_LEN 1048576

class Solution {
public:
    
    char bitmap[MAX_LEN/8] = {0};
    
    void setbit(int num)
    {
        int pos = num / 8;
        int shift = num % 8;
        
        bitmap[pos] = bitmap[pos] | (1 << shift);
    }
    
    bool getbit(int num)
    {
        int pos = num/8;
        int shift = num % 8;
        
        return (bitmap[pos] & (1 << shift));
    }
    
    int convertStringtoNum(string s)
    {
        int sum = 0;
        int c = 0;
        while(s[c] != '\0')
        {
            if(s[c] == '1')
                sum += (1 << c);
            c++;
        }
        return sum;
    }

    bool hasAllCodes(string s, int k) {
          int max_len = (1 << k);
       // cout << max_len << endl;
        
        int len = s.size();
        
        //cout << len << endl;
        for(int i = 0; i < len-k+1; i++)
        {
            string subs = s.substr(i, k);
            reverse(subs.begin(), subs.end());
        
            setbit(convertStringtoNum(subs));
            //cout << subs << endl;
        }
        
        for(int i = 0; i < max_len; i++)
        {
            if(!getbit(i))
                return false;
        }
        return true;
    }
};
// @lc code=end

