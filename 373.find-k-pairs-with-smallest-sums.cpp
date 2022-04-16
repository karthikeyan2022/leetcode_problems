/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start


#define DEBUG   1

#if(DEBUG)
#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;
#endif

#define MAX_LEN 100

#if(0)
//using bool visited array maxes out memory size since we need 10^5 2D array. Hence use set stl for 
// checking whether a pair of index (idx1,idx2) is already inserted into heap or not
bool visited[MAX_LEN][MAX_LEN] = {false,};

void visitarr_init(int x, int y)
{

    if( x >= MAX_LEN || y >= MAX_LEN)
    {
        cout << "check the out of bound size" << endl;
        return;
    }
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            visited[i][j] = false;
        }
    }
}
#endif
// pair which contains one element each from two array. this type is maintained in priority queue ds
struct num_pair
{
    int num1;
    int num2;

    // index in nums array
    int idx1;
    int idx2;
    // constructor
    num_pair(int num1, int num2, int idx1, int idx2) 
        : num1(num1), num2(num2), idx1(idx1), idx2(idx2) {}

};

struct comparePair
{
    // return true if pair2 is less :num_pair with smallest sum 
    bool operator() (num_pair const& pair1, num_pair const& pair2)
    {
        return ((pair2.num1+pair2.num2) < (pair1.num1+pair1.num2)) ? true : false;
    }
};



class Solution {
public:

    // heap of pairs with smallest pair on top of heap
    priority_queue <num_pair, vector<num_pair>, comparePair> pairsHeap;

    // set ds to check if a index pair ([1][2]) is already inserted to heap or not.
    // it can happen
    set<pair<int,int>> indexset;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> retvect;
        int len1 = nums1.size();
        int len2 = nums2.size();
       
        indexset.clear();

        int count = k;
        if(len1 < 1 || len2 < 1) return retvect;

        // initially one pair is pushed to heap (first of both array)
        pairsHeap.push(num_pair(nums1[0], nums2[0], 0, 0));
        indexset.insert(make_pair(0,0));

        while(count-- && !pairsHeap.empty())
        {
            num_pair popelt = pairsHeap.top();
            pairsHeap.pop();

            //cout << popelt.num1 << popelt.num2 << endl;

            vector<int> temp {popelt.num1, popelt.num2};
            retvect.push_back(temp);

            int idx1 = popelt.idx1;
            int idx2 = popelt.idx2;

            // now push the idx1+1. idx2
            pair<int,int> p1(idx1+1, idx2);
            if((idx1+1) != len1 && indexset.find(p1) == indexset.end())
            {
                pairsHeap.push(num_pair(nums1[idx1+1], nums2[idx2], idx1+1, idx2));
                indexset.insert(p1);
              
            }
                         
            // now push the idx1, idx2+1
            pair<int,int> p2(idx1, idx2+1);
            if((idx2+1) != len2 && indexset.find(p2) == indexset.end())
            {
                pairsHeap.push(num_pair(nums1[idx1], nums2[idx2+1], idx1, idx2+1));
                indexset.insert(p2);           
            }
                
        }
        return retvect;
    }
};


#if(DEBUG)

int main()
{
    class Solution* sol = new Solution();

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
  //  nums1.push_back(11);
  //  nums1.push_back(1);

    vector<int> nums2;
    nums2.push_back(3);
   // nums2.push_back(4);
   // nums2.push_back(6);
    int k = 3;

    sol->kSmallestPairs(nums1, nums2, k);
}
#endif
// @lc code=end

