#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // Key value    --> entry in nums[i]
    // Mapped value --> idx in nums[i]
    unordered_map<int,int> simplehash;
    unordered_map<int,int> :: iterator itr;

    vector<int> twoSum(vector<int>& nums, int target) {

        int size = nums.size();
        vector<int> ret;

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

        return ret;
        
    }
};


int main(int argc, char *argv[])
{
    class Solution* sol = new Solution(); // create Solution object
    
   
    char line[300];
    int len = 300;

    // 1. input and output variables declare
    vector<int> nums;
    int target = 9;
    vector<int> indices;

    indices = sol->twoSum(nums, target);


    // delete the solution object
    delete sol;

 }
