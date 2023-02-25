/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        
#if(0)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return (s == t);
#else
        
        int len_s = s.size();
        int len_t = t.size();
        
        if(len_s != len_t) return false;
        
        vector<int> count_s(26, 0);
        vector<int> count_t(26, 0);
        
        for(int a : s)
            count_s[a-'a']++;
            
        for(int a : t)
            count_t[a-'a']++;
        
        for(int i = 0; i < 26; i++)
        {
            if(count_s[i] != count_t[i])
                return false;
        }
        
        return true;
#endif
    }
};
// @lc code=end

