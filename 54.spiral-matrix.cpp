/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:

    int dir = 0;
    int m;
    int n;
    int visited[10][10] = {false};
    
    int getnextcol(int c)
    {
        if(dir == 0) return c+1;
        if(dir == 2) return c-1;
        
        return c;
    }
    
    int getnextrow(int r)
    {
        if(dir == 1) return r+1;
        if(dir == 3) return r-1;
        
        return r;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         m = matrix.size();
        n = matrix[0].size();
        
        int count = m*n;
        /*
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
                visited[i][j] = false;
        }*/
        
      //  cout << m << " " << n << endl;
        
        int r = 0;
        int c = 0;
        dir = 0;
        vector<int> result;
        result.push_back(matrix[0][0]);
        count--;
        visited[0][0] = true;
        
       // cout << count << endl;
        while(count)
        {
            int row = getnextrow(r);
            int col = getnextcol(c);
            
           //  cout << row << " " << col << endl;
            if(row >= 0 && row < m && col >= 0 && col < n && visited[row][col] == false)
            {
                r = row;
                c = col;
                visited[row][col] = true;
               
                result.push_back(matrix[row][col]);
                count--;
            }
            else
            {
                // should change dir to right dir
                dir = (dir + 1) % 4;
            }
        }
        
        
        return result;
    }
};
// @lc code=end

