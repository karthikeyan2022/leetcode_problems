/*
 * @lc app=leetcode id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int maxVal = 0;
        int len = ages.size();
        
         // sort the list based on  ages
         // if ages equal, sort by scores
        for(int i = 0; i < len; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(ages[i] > ages[j])
                {
                    swap(ages[i], ages[j]);
                    swap(scores[i], scores[j]);
                }
                else if(ages[i] == ages[j] && scores[i] > scores[j]) // [BUG FIX]
                {
                    swap(ages[i], ages[j]);
                    swap(scores[i], scores[j]);
                }
            }
        }
        
        vector<int>locscore(len);
        for(int i = 0; i < len; i++)
        {
            locscore[i] = scores[i];
        }
        
        maxVal = locscore[0];
        
        //  for(int a: locscore)
        //     cout << a << " ";
        // cout << endl;    
        for(int i = 1; i < len; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(ages[i] >= ages[j] && scores[i] >= scores[j])
                    locscore[i] = max(locscore[i], scores[i]+locscore[j]);
            }
            
            maxVal = max(maxVal, locscore[i]);
        }
         
        // for(int a: locscore)
        //     cout << a << " ";
        // cout << endl;
        
        return maxVal;
        
    }
};
// @lc code=end

