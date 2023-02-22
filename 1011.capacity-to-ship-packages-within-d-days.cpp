/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start

#define DEBUG   0
#if(DEBUG)
#include<vector>
using namespace std;
#endif

class Solution {
public:

    bool IsShipPossible(vector<int>& weights, int days, int value)
    {
        bool retVal = false;

        int idx = 0;
        int sum = 0;
        while(days)
        {
            sum = 0;

            if(idx == weights.size())
                break;

            while((sum+weights[idx] <= value))
            {
                sum += weights[idx];
                idx++;

                if(idx == weights.size())
                    break;
            }    

            days--;
        }

        if(days < 0)
            return false;
        
        if(idx < weights.size())
            return false;

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int low,high,mid;

        int sum = 0;
        int len = weights.size();

        for(int i = 0; i < len; i++)
        {
            sum += weights[i];
        }

        low = sum / days;
        high = sum;

        while(low < high)
        {
            mid = low + ((high-low)/2);

            // search even lesser mid value
            if(IsShipPossible(weights, days, mid))
            {
                high = mid;
            }
            else // try bigger value
            {
                low = mid+1;
            }
        }

        return low;
    }
};

#if(DEBUG)
int main()
{
    vector<int> weights;


    for(int i = 1; i <= 10; i++)
    {
        weights.push_back(i);
    }
   // weights.push_back(1);
   // weights.push_back(1);
    Solution* sol = new Solution();
    int retval = sol->shipWithinDays(weights, 5);
}
#endif
// @lc code=end

