/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#define DEBUG   0
#if(DEBUG)
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
#endif

class Solution {
public:

    string getStringGroup(string str)
    {
        sort(str.begin(), str.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map< string /*str_grp*/, vector<string>> wordslist;
        
        vector<vector<string>> retVect;
        
        for(string str : strs)
        {
            //string str_grp = str;
            //sort(str_grp.begin(), str_grp.end());
            wordslist[getStringGroup(str)].push_back(str);
            
        }
        
        for(auto it = wordslist.begin(); it != wordslist.end(); it++)
        {
            retVect.push_back((*it).second);
        }
        
        return retVect;
    }
};


#if(DEBUG)
int main()
{
    Solution* sol = new Solution();

    vector<string> str_list;

    str_list.push_back("eat");
    str_list.push_back("tan");
    str_list.push_back("ate");
    str_list.push_back("nat");
    str_list.push_back("bat");

    vector<vector<string>> str_group_list = sol->groupAnagrams(str_list);
}
#endif
// @lc code=end

