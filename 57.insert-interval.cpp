/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
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
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector< vector<int>> retVect;
        
        int len = intervals.size();
        if(len == 0) { retVect.push_back(newInterval); return retVect;}
        
        bool bMerged = false;
        
        // if new interval starts earlier than first interval
        if(newInterval[1] < intervals[0][0])
        {
            retVect.push_back(newInterval);
            bMerged = true;
        }
        
        for(int i = 0; i < len; i++)
        {
            // check if newInterval is overlapping,
            // if yes, merge and insert. continue
            if(!bMerged && isOverlapping(intervals[i], newInterval))
            {
                vector<int> temp = intervals[i];
                temp[0] = min(newInterval[0], intervals[i][0]);
                temp[1] = max(newInterval[1], intervals[i][1]);
                
                retVect.push_back(temp);
                
                bMerged = true;
                continue;
            }
            
            // insert the intervals into retVect array. 
            // if overlapping with last retVect element, merge/modify it
           
            if(i != 0 && isOverlapping(intervals[i], retVect.back()))
            {
                vector<int>& temp = retVect.back();
                
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else // i == 0, or normal non-overlapping insert
            {
                 retVect.push_back(intervals[i]);
            }      
        }
        
        if(!bMerged)
        {
            retVect.push_back(newInterval);
            sort(retVect.begin(), retVect.end(), mysort);
        }
            
        
        return retVect;
        
    }
};
// @lc code=end

