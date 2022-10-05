/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int K = k;
        int maxLen = 0;
        int len = s.size();
        vector<bool> count(26,0);
        
        for(int i = 0; i < len; i++)
        {
            if(!count[s[i]-'A'])
                count[s[i]-'A'] = true;
        }
        
        for(int i = 0; i < 26; i++)
        {
            K = k;
            char c = 'A' + i;
            
            if(!count[i])
                continue;
            
            int lp = 0;  
            int j = 0;
            while(j < len)
            {
                if(s[j] != c)
                {
                    if(K == 0)
                    {
                        while(s[lp] == c)
                            lp++;
                        
                        lp++;
                    }
                    else
                    {
                        K--;
                    }
                }
               // cout << "left: " << lp << " right: " << j << endl;
                maxLen = max(maxLen, j - lp + 1);
                j++;
            }   
        }
        
        return maxLen;
        
    }
};
// @lc code=end

