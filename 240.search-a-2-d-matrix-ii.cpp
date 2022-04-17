/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:

    int M;
    int N;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         M = matrix.size();
        N = matrix[0].size();
    
        // last index of row and col
        int m = M-1;
        int n = N-1;
        
        // shrink the given 2D matrix first
        // shrink row
       // while(matrix[m][0] > target && m > 0)
       //     m--;
        
        // shrink col
       // while(matrix[0][n] > target && n > 0)
        //    n--;
         
        
        // diagonal triangle cut across top right to bottom left
        // shrink the diagonal through row++ or col--
        int row = 0;
        int col = n;
        
        while(row <= m && col >= 0)
        {
            int ele = matrix[row][col];
            
            if(ele == target)
            {
                return true;
            }
            
            if(ele > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        // start bin search from m th row --> 0 .. n
        /*
        int count = m+1;
        while(count--)
        {
        
        int left = 0;
        int right = n;
        int mid;
        
        
        while(left <= right)
        {
            mid = left + ((right-left)/2);
            
            
            if(matrix[m][mid] == target)
            {
                return true;
            }
            
            if(left == right) break;
             
            if(matrix[m][mid] > target)
            {
                right = mid -1;
            }
            else
            {
                left = mid + 1;    
            }
        }
            
        m--;
        }*/
        
        
        
        
    
        return false;
    }
};
// @lc code=end

