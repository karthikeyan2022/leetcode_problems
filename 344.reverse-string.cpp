/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start

#define OLD_CODE 0

class Solution {
public:

    void reverseString(vector<char>& s) {

      //cout << s.size();
      int length = s.size();

      if(length < 2) return;  

#if(OLD_CODE)
         int trav = length/2;
          int last = length-1;
          for(int i = 0; i < trav; i++)
          {
              char temp = s[i];
              s[i] = s[last];
              s[last] = temp;

              last--;
          }

#else
      int first = 0; 
      int last = length-1;

      while(first < last)
      {
           char temp = s[first];
              s[first] = s[last];
              s[last] = temp;

              first++;
              last--;
      }
      
        
    }
#endif

};
// @lc code=end

