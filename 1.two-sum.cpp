/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#define DEBUG   0
#define TOGGLE_CODE    1

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        int size = nums.size();
        vector<int> ret;

#if(TOGGLE_CODE)
        unordered_map<int,int> simplehash;
        simplehash.clear();
       
        for (int i = 0; i < size; i++)
        {
            unordered_map<int,int> :: iterator itr;

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
int main()
{
    class Solution* sol = new Solution();

    ListNode* nodes[10];
    int arr1[3] = {2,4,3}; 
    int arr2[3] = {5,6,4};

    ListNode* prev = nullptr;

    for (int i = 0; i < 3; i++)
    {
        nodes[i] = new ListNode(arr1[i], prev);

        prev = nodes[i];
    }

    prev = nullptr;

    for (int i = 3; i < 6; i++)
    {
        /* code */
        nodes[i] = new ListNode(arr2[i-3], prev);

        prev = nodes[i];
    }
    
    ListNode* l1 = nodes[2];
    ListNode* l2 = nodes[5];
    ListNode* retnode = sol->addTwoNumbers(l1,l2);

}
#endif
// @lc code=end



