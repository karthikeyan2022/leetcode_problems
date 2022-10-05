/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    
    bool board[10][10] = {0};
    int N = 0;
    bool canPlacehere(int r, int c)
    {
        int R = r;
        int C = c;
        
        // row check
        while(--R >= 0) { if(board[R][C]) return false;}
            
        // column check
        R = r; C = c;
        while(--C >= 0) { if(board[R][C]) return false;}
        
        R = r; C = c;
        
        while(C >= 0 && R >= 0)
        {
            if(board[R][C])
                return false;
            
            C--;R--;
        }
        
        R = r; C = c;
        
        while(C < N && R >= 0)
        {
            if(board[R][C])
                return false;
            
            C++;R--;
        }
        
        
        return true;
    }
    
    vector<string> makestr()
    {
        vector<string> strarr;
        for(int i = 0; i < N; i++)
        {
            string str;
            
            for(int j = 0; j < N; j++)
            {
                char c = (board[i][j]) ? 'Q' : '.';
                str.push_back(c);
            }
            strarr.push_back(str);
        }
        
        return strarr;
    }
    
    bool doRecursive(int idx, int n, vector<vector<string>>& retVect)
    {
        if(idx == n)
        {
            retVect.push_back(makestr());
            return true;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(canPlacehere(idx, i))
            {
                board[idx][i] = true;
                doRecursive(idx+1, n, retVect);
                board[idx][i] = false;
            }
        }
        
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        N = n;
        vector <vector<string>> retVect;
        
        if(n <= 1)
        {
            vector<string> temp = {"Q"};
            retVect.push_back(temp);
            return retVect;
        }
        
        // start from level 0
        doRecursive(0, n, retVect);
        
        
        
        return retVect;
    }
};
// @lc code=end

