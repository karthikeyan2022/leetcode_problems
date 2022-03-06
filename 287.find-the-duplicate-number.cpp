/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start

#define DEBUG   0

#if(DEBUG)
#include "parse.h"
using namespace std;
#endif

#define BYTE_MAX_RANGE   (100000 + 1)

class Solution {
public:

    char bitmap[BYTE_MAX_RANGE];

    bool getbit(int num, char* bitmap)
    {
        int group = num / 8;
        int pos = num % 8;

        int comp = 0;
        comp = 1 << pos;

        return (bitmap[group] & comp); 
    }

    void setbit(int num, char* bitmap, int length)
    {
        int group = num / 8;
        int pos = num % 8;

        int comp = 0;
        comp = 1 << pos;

        bitmap[group] = (bitmap[group] | (comp)) ;
    }


    int countOfLessThanEqual(int num, vector<int>& nums)
    {
        int length = nums.size();
        int count = 0;


        for(int i = 0; i < length; i++)
        {
            if(nums[i] <= num)
                count++;
        }
        return count;
    }
    int findDuplicate(vector<int>& nums) {

         int length = nums.size();
#if(0)
        int duplicateNum = -1;
       

        //char bitmap[length];
        memset(bitmap, 0, sizeof(char)*length);

        for(int i = 0; i < length; i++)
        {
            if(getbit(nums[i], bitmap))
            {
                return nums[i];
            }
            else
            {
                setbit(nums[i], bitmap, length);
            }
        }
        return duplicateNum;

#endif
        int low, high, mid;

        low = 1;
        high = length-1;
        mid = -1;
        int ans = 0;
        while(low <= high)
        {
            mid = low + ((high-low)/2);

            // if the number doesnt contain duplicates, move low -->
            if(countOfLessThanEqual(mid, nums) <= mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid-1;
                ans = mid;
            }
        }

        return ans;
    }
};



#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<int> nums = {1,3,4,2,2};

    sol->findDuplicate(nums);


    delete sol;
}
#endif
// @lc code=end

