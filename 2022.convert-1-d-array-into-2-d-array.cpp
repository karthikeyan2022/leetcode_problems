/*
 * @lc app=leetcode id=2022 lang=cpp
 *
 * [2022] Convert 1D Array Into 2D Array
 */

// @lc code=start

#define DEBUG 0
#if(DEBUG)
#include<iostream>
#include<vector>
#include<list>
using namespace std;
#endif


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> retVect;

        int len = original.size();
        
        // if 2d cant be consructed, return empty 
        if( len != (m*n)) return retVect;

        // populate n (column) times in tempVector(col) and push it to retVect(rows)
        int i = 0;
        int j;
        while(i < len)
        {          
            j = n;
            vector<int> tempVect;

            while(j-- && i < len)
            {
                tempVect.push_back(original[i]);
                i++;
            }

            retVect.push_back(tempVect);
        }


        return retVect;
    }
};
// @lc code=end

