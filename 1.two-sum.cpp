/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#define DEBUG   0
#define TOGGLE_CODE    1

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
        unordered_map<int,int> simplehash;
        unordered_map<int,int> :: iterator itr;

        for (int i = 0; i < size; i++)
        {
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
    class Solution* sol = new Solution();
    string inputstr;
    inputstr = argv[0];

    cout << inputstr << endl;
    reverse(inputstr.begin(), inputstr.end());
    cout << inputstr << endl;

    size_t spos = inputstr.find(".");
    size_t epos = inputstr.find("\\");

    cout << spos << " " << epos << endl;

    string fname = inputstr.substr(spos,epos);

    cout << fname << endl;
    for(int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    vector<int> nums = {1,2,3,4,5};
    inputstr = "hello";

    //parseVector(nums, inputstr);
    vector<int> ret = sol->twoSum(nums, 9);
    
   // cout << ret[0] << ret[1] << endl;
 }
#endif
// @lc code=end