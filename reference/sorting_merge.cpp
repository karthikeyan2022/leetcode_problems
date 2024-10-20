/*
 * Merge sort implementation
 * ascending order sort
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    // Recursive function
    // Split the array into half until it have 1 or 2 elements
    void splitAndMerge(int left, int right, vector<int>& nums)
    {
        // base case: if elements are one or two, then stop
        int len = right - left + 1;

        if(len <= 2)
        {
            // not sorted
            if(nums[left] > nums[right])
            {
                swap(nums[left], nums[right]);
            }
            return;
        }

        // 1.) Split and go recursive
        int mid = left + ((right-left)/2);

        splitAndMerge(left, mid, nums);
        splitAndMerge(mid+1, right, nums);

        // 2.) use two pointer traversing and sort it
        // 2.1: move across left and right sub array and sort
        int lp = left;
        int rp = mid+1;
        vector<int> temp;
        while((lp <= mid) && (rp <= right))
        {
            // sorted
            if(nums[lp] < nums[rp])
            {
                temp.push_back(nums[lp++]);
            }
            else
            {
                temp.push_back(nums[rp++]);
            }
        }

        // 2.2: push the remaining entries
        while(lp <= mid) {
            temp.push_back(nums[lp++]);
        }

        while(rp <= right) {
            temp.push_back(nums[rp++]);
        } 

        int idx = 0;
        for(int i = left; i <= right; i++)
        {
            nums[i] = temp[idx++];
        }

    }

public:
    vector<int> mergeSort(vector<int> nums)
    {
        splitAndMerge(0, nums.size()-1, nums);
        return nums;
    }
};


int main()
{
    class Solution* sol = new Solution(); 

    vector<int> nums = {1, 3, 5, 2, 4, 10};

    vector<int> retarr = sol->mergeSort(nums);

    cout << "sorted: ";
    for(int num : retarr)
        cout << num << " ";
    cout << endl;
}