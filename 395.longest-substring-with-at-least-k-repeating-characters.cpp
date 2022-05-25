/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start

#define DEBUG   0

#define BRUTE_FORCE 0
#define DIVIDE_CONQ 1
#define MODE 1


#if(DEBUG)
#include<iostream>
#include<vector>
#include "parse.h"
using namespace std;
#endif

class Solution {
public:

#if(MODE==BRUTE_FORCE) 

// BRUTE FORCE. accepted
    long count[26];
    long hist[26] = {0,};
    void init_count()
    {
        for(int i = 0; i < 26; i++)
            count[i] = 0;
    }
    
    bool isSubstring(int k)
    {
        for(int i = 0; i < 26; i++)
        {
            if(count[i] < k && count[i] > 0)
                return false;
        }
        
        return true;
        
    }
     
    int longestSubstring(string s, int k) {
        
        int len = s.size();
        int retVal = 0;
        init_count();
             
        for(int i = 0; i < len; i++)
        {
            hist[s[i]-'a']++;
        }
        
        for(int i = 0; i < len; i++)
        {
            if(hist[s[i]-'a'] < k) continue;
            init_count();
           
            for(int j = i; j < len; j++)
            {   
                if(hist[s[j]-'a'] < k) break;
                
                count[s[j]-'a']++;
                
                if(isSubstring(k))
                {
                    retVal = max(retVal, j-i+1);
                }             
            }
      
        }       
        return retVal;
    }
#else
    // divide and conquer approach
    int findlongSubstring(string s, int st, int end, int k)
    {
        // why and how ?
        // commenting this line also works
        // just an optimization
        if((end-st) < k) return 0;

        int count[26] = {0,};

        for(int i = st; i < end; i++)
        {
            count[s[i]-'a']++;
        }

        int midNext;

        // i ~= mid
        for(int i = st; i < end; i++)
        {
           if(count[s[i]-'a'] >= k) continue;

           // remove contiguous invalid chars by checking and use midNext 
           midNext = i+1;
           while(midNext < end && count[s[midNext]-'a'] < k) midNext++;

           return max(findlongSubstring(s,st, i,k), findlongSubstring(s,midNext,end,k));

        }

        // never reaches here if not a proper substring
        return (end-st);
    }

    int longestSubstring(string s, int k) {
        return findlongSubstring(s,0, s.size(), k);
    }
#endif
};

#if(DEBUG)

int main()
{
    class Solution* sol = new Solution();

    string s = "aaabbb";
    int k = 3;
    
    cout << sol->longestSubstring(s,k);
}
#endif
// @lc code=end

