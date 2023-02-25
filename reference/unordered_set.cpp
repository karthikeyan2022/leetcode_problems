#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
        
    unordered_set<int> simplehash;
    unordered_set<int> :: iterator itr;
    int len = nums.size();
    
    for(int i = 0; i < len; i++)
    {
        // get the itr as result of finding the entry
        itr = simplehash.find(nums[i]);
        // if the entry is already present
        if(itr != simplehash.end())
        {
               return true;
        }
        
        // add the entry to the set
        simplehash.insert(nums[i]);
    }
    return false;
}


int main()
{
    vector<int> nums;
    nums.push_back(1);

    if(containsDuplicate(nums))
        cout << "duplicate" << endl;
    else
        cout << "unique" << endl;    
}

// @lc code=end

