/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> retVect;
        
        int len = nums.size();
        
        if(len < 3) return retVect;
        
        // sort the list so that we have -ve numbers,.. 0,.., +ve number
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for(int i = 0; i < len; i++)
        {
            // if -ve number then break. since sum can be made with first -ve out of 3
            if(nums[i] > 0) break;
            
            // remove duplicate
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            sum = 0 - nums[i];
            
            // this is to shortern the kth (3rd loop) in every iteration
            int high = len-1;
            
            for(int j = i+1; j < len; j++)
            {
                // remove duplicates
                if(j > 0 && j > i+1 && nums[j] == nums[j-1]) continue;
                
                for(int k = high; k >= j+1; k--)
                {
                    // if less than sum, no need to proceed checking
                    if(nums[j]+nums[k] < sum) break;
                    
                    // remove duplicates
                    if(k < len-1 && k >= j+1 && nums[k] == nums[k+1]) continue;
                    
                    // equals means push to the return vector
                    // update high var
                    if(nums[j]+nums[k] == sum)
                    {
                        vector<int> temp = { nums[i], nums[j], nums[k]};
                        retVect.push_back(temp);
                        
                        high = k;
                        //break; no need
                    }
                    else if(nums[j] + nums[k] > sum) // update high var
                    {
                        high = k;
                    }
                }
            }
        }
        
        return retVect;
    }
};
// @lc code=end

