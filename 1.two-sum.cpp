/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#define DEBUG           1
#define TOGGLE_CODE     1

#if(DEBUG)
#include "parse.h" // parse.h is in .\util directory (see build.bat)
using namespace std;
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int size = nums.size();
        vector<int> ret;

#if(TOGGLE_CODE)
        // Key value    --> entry in nums[i]
        // Mapped value --> idx in nums[i]
        unordered_map<int,int> simplehash;
        unordered_map<int,int> :: iterator itr;

        for (int idx = 0; idx < size; idx++)
        {
            itr = simplehash.find(nums[idx] /*key*/);

            // if value is found(matching num), return the indices
            if(itr != simplehash.end())
            {
                   ret.push_back(itr->second /*hashed idx*/);
                   ret.push_back(idx         /*current idx*/);
                   return ret; 
            }

            // insert the idx to its pairnum key
            //find other pair and insert to hash
            int pairnum = target - nums[idx];

            // pairnum is key value, idx is mapped value
            simplehash[pairnum] = idx; 

        }
#else
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
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

#if(DEBUG)
int main(int argc, char *argv[])
{
    class Solution* sol = new Solution(); // create Solution object
    
    FILE* fp = parseFileByFstream(argv[0]);
    char line[300];
    int len = 300;

    // 1. input and output variables declare
    vector<int> nums;
    int target;
    vector<int> indices;

    // 2. get values for input variables
    // 2.1 Get the nums array 
    //vector<int> nums = {1,2,3,4,5};
    if(fgets(line, len, fp) != NULL)
    {
        std::cout << line << std::endl;

        if(!parseVector(line, nums))
        {
            fclose(fp);
            exit(-1);
        }
    }
    fclose(fp);

    // 2.2 Get the target value
    target = 9; // [TODO]

    indices = sol->twoSum(nums, target);
    
    cout << "Indices of two sum is : ";
    cout << indices[0] << " " << indices[1] << endl;

    // delete the solution object
    delete sol;

 }
#endif
// @lc code=end