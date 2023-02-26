/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [659] Encode and Decode Strings
 * https://www.lintcode.com/problem/659/
 */

// @lc code=start

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here

        // vector length
        int len = strs.size();
        if(len == 0) return 0;

        string encoded_str = strs[0];
        for(int i = 1; i < len; i++)
        {   
            encoded_str = encoded_str + ":" + strs[i]; 
        }

        cout << encoded_str << endl;
        return encoded_str;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> strs;
        // string length
        int len = str.size();
        string s;
        for(int i = 0; i < len; i++)
        {
            if(str[i] == ':')
            {
                strs.push_back(s);
                s.clear();
                continue;
            }

            s.push_back(str[i]);

        }

        // last string
        strs.push_back(s);

        return strs;
    }
};