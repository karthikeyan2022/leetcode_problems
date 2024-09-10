/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start

#define MODE 2
#define DEBUG 0

#if(DEBUG)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
#endif

class Solution {
public:
    bool isAnagram(string s, string t) {
        
#if(MODE == 0)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return (s == t);
#elif(MODE == 1)
        
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
#elif(MODE == 2)

        unordered_map<char, int> count;
        unordered_map<char, int> :: iterator it;
        // increment freq
        for(char c : s)
            count[c]++;

        // decrement frequency
        for(char c : t)
            count[c]--;

        // check if zero. zero? anagram
        for(it = count.begin(); it != count.end(); it++)
        {
            int val = it->second;

            if(val != 0)
                return false;
        }

        return true;
#endif
    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    string s = "anagram";
    string t = "nagaram";

    cout << "is anagram?" << sol->isAnagram(s, t) << endl;
}
#endif
// @lc code=end

