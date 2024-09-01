/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#define DEBUG 0

#if(DEBUG)
#include ".\util\init.h"
#endif

class Solution {
public:

    vector<vector<int>> retVect;
    int gLen = 0;
    int gCount = 0;
    
    void doRecursive(int idx, int count, vector<int>& index, vector<int>& nums)
    {   
        if(count == gCount)
        {
            vector<int> temp;
            for(auto val: index)
            {
                temp.push_back(nums[val]);
                //cout << val << " ";
            }
            //cout << endl;
            retVect.push_back(temp);
            return;
        }
        
        for(int i = idx+1; i < gLen; i++)
        {   if(i != idx+1 && nums[i] == nums[i-1])
                continue;
            index.push_back(i);
            doRecursive(i, count+1, index, nums);
            index.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        retVect.clear();
        vector<int> index;
        gLen = nums.size();
        
        vector<int> dummy; 
        retVect.push_back(dummy);
        
        for(int c = 1; c <= gLen; c++)
        {
            gCount = c;
            index.clear();
            
            for(int i = 0; i < gLen; i++)
            {
                // track the index and make several combinations with count c
                if(i != 0 && nums[i] == nums[i-1])
                    continue;
                    
                index.push_back(i);
                doRecursive(i, 1, index, nums);
                index.pop_back();
            }  
        }
        
        return retVect;
    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<int> nums;
    for(int i = 1; i <= 3; i++){
        nums.push_back(i);
    }
    nums[2] = 2;
    
    nums.push_back(3);
    nums.push_back(4);
    vector<vector<int>> retVect = sol->subsets(nums);

    for(auto vect : retVect) {
        vector<int> temp = vect;
        cout << "[ ";
        for(auto num : temp)
            cout << num << " ";
        cout << "]" << endl;
    }
}
#endif
// @lc code=end

