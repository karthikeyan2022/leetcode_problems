/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:

    char bitmap[256/8] = {0};
    
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
    
    void clearall()
    {
        for(int i = 0; i < 256/8; i++)
            bitmap[i] = 0;
    }

    int lengthOfLongestSubstring(string s) {

#if(1)
    // my solutionpassed but not efficient
        int maxlen = 0;
        
        int len = s.size();
        
        if(len == 0) return 0;
        
        bool check[26] = {0};
        
        unordered_map<char, bool> checkhash;
        
        maxlen = 1;
        //int sum = s[0];
        
        checkhash[s[0]] = 1;
        int leftp = 0;
        for(int i = 1; i < len; i++)
        {   
            clearall();
            setbit(int(s[i]));
            int j = i-1;
           // cout << s[i] << " ";
            while(j >= 0 && !getbit(int(s[j])))
            {
               // cout << s[j] << " ";
                setbit(int(s[j]));
                j--;
            }
            
            maxlen = max(maxlen, i-j);
           
            // cout << endl;
        }
      
        return maxlen;
#else

    
    // sliding window o(n)solution
    // based on increasing index, we can easily track the continuous len
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
#endif
    }
};
// @lc code=end

