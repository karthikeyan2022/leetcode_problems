
#define DEBUG 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool checkForGroup(vector<int>& nums, vector<int>& visited, int currsum, int idx, int subsetsum, int group)
    {
        // If all  groups can be formed, return true;
        if (group == 0)
            return true;

        // subset canot be formed with current sum
        if (currsum > subsetsum)
            return false;

        if (subsetsum == currsum)
        {
            // one group is completed. now check for next group
            // Similar to call in main function.
            return checkForGroup(nums, visited, 0, 0, subsetsum, group-1);
        }
            
        
        for(int i = idx; i < nums.size(); i++)
        {
            if(visited[i])
                continue;

            //if(nums[i] > subsetsum)
            //    continue;
            
            visited[i] = true;
            bool bGroup = checkForGroup(nums, visited, currsum+nums[i], i+1, subsetsum, group);
            

            if(bGroup)
            {
                return true;
            }
          
            visited[i] = false;
            
        }

        //cout << "subsetsum: " << subsetsum << endl;
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int len = nums.size();
        int sum = 0;
        for(int num : nums)
            sum += num;
        
        if ((sum % k) != 0)
            return false;

        cout << "sum: " << sum << endl;

        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> visited(len,0);

        return checkForGroup(nums, 
                            visited, 
                            0 /*currsum*/,  
                            0 /* start_idx */ , 
                            (sum / k) /*subsetsum */, 
                            k /*group*/);
    }
};

int main()
{
    class Solution* sol = new Solution();

    vector<int> nums = {4,5,9,3,10,2,10,7,10,8,5,9,4,6,4,9};

    if(sol->canPartitionKSubsets(nums, 5))
    {
        cout << "test passed" << endl;
    }
    else
    {
        cout << "test failed" << endl;
    }

}