/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#define TOGGLE_CODE    1


class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        int size = nums.size();
        vector<int> ret;

#if(TOGGLE_CODE)
        unordered_map<int,int> simplehash;
        simplehash.clear();
       

        for (int i = 0; i < size; i++)
        {
            unordered_map<int,int> :: iterator itr;

            itr = simplehash.find(nums[i]);

            // if value is found( matching num) and it is not the same one
            if(itr != simplehash.end())
            {
                   ret.push_back(itr->second);
                   ret.push_back(i);
                   return ret; 
            }


            // insert the index to its pairnum key
            //find other pair and insert to hash
            int pairnum = target - nums[i];

            // pairnum is key, i is value
            simplehash[pairnum] = i; 


        }

#else
        
        for(int i = 0; i < size; i++)
        {
            // if one number is greater than target, 
            // no need to search for its pair
            //if(nums[i] > target && target > 0) continue;

            for(int j = 0; j < size; j++)
            {
                //if(nums[j] > target && target > 0) continue;

                // to avoid comparing same number
                if(i == j) continue;

                if((nums[i]+nums[j]) == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        
#endif
        return ret;
        
    }
};
// @lc code=end



