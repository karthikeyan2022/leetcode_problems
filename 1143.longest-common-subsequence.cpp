/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int count[1002][1002] = {0};
    int longestCommonSubsequence(string text1, string text2) {
        
        int len1 = text1.size();
        int len2 = text2.size();
        
        if(len1 == 0 || len2 == 0) return 0;
        

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                
                // if equal, check diagonally + 1
                if(text1[i-1] == text2[j-1])
                {
                    count[i][j] = max(count[i][j], 1+count[i-1][j-1]);
                }
                else // check left and up number
                {
                    count[i][j] = max(count[i][j], count[i][j-1]);
                    count[i][j] = max(count[i][j], count[i-1][j]);
                }
            }
        }
        
//      cout << len1 << " " << len2 << endl;
//      for(int i = 1; i <= len1; i++)
//      {
//          for(int j = 1; j <= len2; j++)
//          {
//              cout << count[i][j] << " ";
//          }
//          cout << endl;
//       }
        
        return count[len1][len2];      
    }
};
// @lc code=end

