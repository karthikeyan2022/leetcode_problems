/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start

bool mysort(vector<int>& int1, vector<int>& int2)
{
    if(int1[0] < int2[0])
        return true;
        
    if(int1[0] == int2[0] && int1[1] < int2[1])
        return true;
        
    return false;
}

class Solution {
public:

    bool isOverlapping(vector<int> int1, vector<int> int2)
    {
        if(int2[0] >= int1[0] && int2[0] <= int1[1])
            return true;
        
        if(int1[0] >= int2[0] && int1[0] <= int2[1])
            return true;
        
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> retVect;
        
        // sort the intervals based on starti
        sort(intervals.begin(), intervals.end(), mysort);
        int len = intervals.size();
        
        if(len == 0) return retVect;
        
        vector<int> temp = intervals[0];
        retVect.push_back(temp);
        
        for(int i = 1; i < len; i++)
        {
            if(isOverlapping(intervals[i], retVect.back()))
            {
                vector<int>& temp = retVect.back();
                
                //temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
                
            }
            else
            {
                retVect.push_back(intervals[i]);
            }
        }
        
        
        
        return retVect;
    }
};
// @lc code=end

