/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:

    bool visited[300][300] = {false};
    int m;
    int n;
    void dorecur(int i, int j, vector<vector<char>>& grid)
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return;
        
        visited[i][j] = true;
        
        // go top and visit
        if(i > 0 && !visited[i-1][j] && grid[i-1][j] == '1')
        {
            dorecur(i-1,j, grid);
        }
        
        // go down and visit
        if(i < (m-1) && !visited[i+1][j] && grid[i+1][j] == '1')
        {
            dorecur(i+1,j,grid);
        }
        
        // go left
        if(j > 0 && !visited[i][j-1] && grid[i][j-1] == '1')
        {
            dorecur(i,j-1,grid);
        }
        
        // go right
        if(j < (n-1) && !visited[i][j+1] && grid[i][j+1] == '1' ) 
        {
            dorecur(i,j+1,grid);
        }
        
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {          
                    // traverse and visit neighbour islands
                    dorecur(i,j, grid);
                    
                    count++;
                }
            }
        }
        
        return count;
    }
};
// @lc code=end

