/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start

#define DEBUG 0

#if(DEBUG)
#include <iostream>
#include <vector>
using namespace std;
#endif

struct TRIE
{
    struct TRIE* children[2]; // 0 or 1
    int num;
};

class Solution {
public:
    struct TRIE root;

    struct TRIE* getNewTrie()
    {
        struct TRIE* pstTrie = new TRIE();
        pstTrie->num = -1;
        pstTrie->children[0] = pstTrie->children[1] = 0;
        return pstTrie;
    }

    void initTrie()
    {
        root.num = -1;
        root.children[0] = 0;
        root.children[1] = 0;
    }

    void insertToTrie(int num)
    {
        struct TRIE* curr = &root;
        //32 bit integer - 2,147,483,647 (2^31 -1).
        // 30-bit
        for(int bit = 30; bit >= 0; bit--)
        {
            // if bit set, create chilren[1]
            bool set = ((num >> bit) & 1);

            if(curr->children[set] == nullptr) {
                curr->children[set] = getNewTrie();
            }

            // go to next level
            curr = curr->children[set];          
        }

        // set the number at last level
        curr->num = num;
    }

    int getMaxXOR(int num)
    {
        struct TRIE* curr = &root;

        for(int bit = 30; bit >= 0; bit--)
        {
            // if bit set, flip it and check unset child
            bool set = ((num >> bit) & 1);
            set = !set;            

            // try to go to flipped child for max XOR
            if(curr->children[set])
            {
                curr = curr->children[set];  
            }
            else // if not found, go other way (this will be there)
            {
                curr = curr->children[!set];
            }
        }

        // set the number at last level
        return (num ^ curr->num);
    }

    int findMaximumXOR(vector<int>& nums) {
        
        int maxVal = 0;
        initTrie();

        for(int num : nums) {
            insertToTrie(num);
        }

        for(int num : nums) {
            maxVal = max(maxVal, getMaxXOR(num));
        }
        
        return maxVal;
    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    vector<int> nums = {3,10,5,25,2,8};
    sol->findMaximumXOR(nums);

}
#endif
// @lc code=end

