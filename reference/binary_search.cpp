/*
 * Binary search implementation
 * https://leetcode.com/problems/binary-search/
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int len = nums.size();

        int left = 0;
        int right = len -1;
        int mid; 

        while(left <= right)
        {
            // mid is calculated differently to handle overflow case
            mid = left + ((right - left)/2);

            if(nums[mid] == target)
                return mid;

            // = is not included here since it is handled above
            // target is in left subarr
            if(target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // no need if = is there in while
        //if(nums[left] == target) 
        //    return left;      
        return -1;
    }
};


int main()
{
    class Solution* sol = new Solution();

    vector<int> nums = {1, 2, 3, 4 , 5 };

    cout << sol->search(nums, 4) << endl;
}