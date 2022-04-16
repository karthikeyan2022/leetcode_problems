/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start



#define RECUR       0
#define DP          1
#define MODE        (1)

#define MAX_N   102

#define DEBUG   0
#if(DEBUG)
#include "parse.h" // parse.h is in .\util directory (see build.bat)
using namespace std;
#endif

class Solution {
public:

    int gsum = 0;
    int length = 0;

    int rob(vector<int>& nums) {

        length = nums.size();
        gsum = 0;

        if(length == 1) return nums[0];

        if(length == 2)
        {
            return (nums[0] > nums[1]) ? nums[0] : nums[1];
        }
        
        if(length == 3)
        {
            int MAX = max(nums[0],nums[1]);
            return max(MAX, nums[2]);
        }
  
        int maxsum[MAX_N] = {0};

        maxsum[0] = nums[0];
        maxsum[1] = nums[1];
        
        // start loop from idx 2.. get the max of i-2 and i-3 and update maxsum
        for(int i = 2; i <= length-2; i++)
        {
            int max1 = maxsum[i-2]+nums[i];

            int max2 = 0;
            if(i-3 >= 0)
                max2 = maxsum[i-3]+nums[i];

            maxsum[i] = (max1 > max2) ? max1 : max2;

        }

        int finalmax = max(maxsum[length-2], maxsum[length-3]);

        maxsum[0] = 0;
        maxsum[1] = nums[1];
        for(int i = 2; i <= length-1; i++)
        {
            int max1 = maxsum[i-2]+nums[i];

            int max2 = 0;
            if(i-3 >= 0)
                max2 = maxsum[i-3]+nums[i];

            maxsum[i] = (max1 > max2) ? max1 : max2;

        }

        int finalmax2 = max(maxsum[length-2], maxsum[length-1]);

        cout << finalmax << finalmax2 << endl;
        return max(finalmax,finalmax2);

  
    }
};


#if(DEBUG)
int main(int argc, char *argv[])
{
    class Solution* sol = new Solution(); // create Solution object
    
    vector<int> arr = { 200,3,140,20,10};
   
    int sum = sol->rob(arr);

    delete sol;

 }
 #endif
// @lc code=end

