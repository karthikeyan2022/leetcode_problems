/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#define DEBUG	0

#if(DEBUG)
#include<vector>
#include<iostream>
#include<algorithm>
#include "parse.h"
using namespace std;
#endif

//similar to permutations 1 problem except
//to prevent duplicates, I ended up removing the second swap and passing the array by value.
class Solution {
public:

    vector<vector<int>> retVect;

    // pass by value of nums - vector<int> is needed
    // why pass by reference vector<int>& is not working?
    void doRecursive(vector<int> nums, int begin, int len)
    {
        // if no. of swaps reached the end --- length of vector, push this array variant    
        if(begin == len)
        {
#if(DEBUG)
			cout << " --> ";
			printVector(nums);
#endif
            retVect.push_back(nums);
            return;
        }

        for(int i = begin; i < len; i++)
        {
            if(begin != i && nums[begin] == nums[i]) continue;

#if(DEBUG)			
			cout << " " << begin << " " << i << " " << "|";
#endif
            // swap 
            swap(nums[begin], nums[i]);

            doRecursive(nums, begin+1, len);

            // swap back
            //swap(nums[begin], nums[i]);
            

        }

#if(DEBUG)
		cout << endl;
		if(begin != 0)
		{			
			printSpaces(begin-1);
		}
#endif

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        retVect.clear();

        sort(nums.begin(), nums.end());  

        doRecursive(nums, 0, nums.size());

        return retVect;  
    }
};

#if(DEBUG)
/*
 * Main static function 

 
 */
int main()
{
    class Solution* sol = new Solution();

    vector<int> arr = {1,2,1,2};

    vector<vector<int>> result = sol->permuteUnique(arr);

	return 0;
}
#endif
// @lc code=end

