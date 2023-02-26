/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start

#define DEBUG 0

#if(DEBUG)
#include<string>
#include<vector>
using namespace std;
#endif

class Solution {
public:

    bool isValid(vector<char>& line)
    {
        bool valid[10] = {0,};

        for(int i = 0; i < 9; i++)
        {
            if(line[i] == '.')
                continue;

            if(valid[line[i]-'0'])
                return false;

            valid[line[i]-'0'] = 1;
        }

        return true;
    }

    bool isAllRowsColumnsValid(vector<vector<char>>& board)
    {
        vector<char> temp;
        //traverse all rows
        for(int r = 0; r < 9; r++)
        {
            temp.clear();

            for(int c = 0; c < 9; c++)
            {   
                temp.push_back(board[r][c]);
            }

            // check for valid
            if(!isValid(temp))
                return false;
 
        }

        // traverse all columns
        for(int c = 0; c < 9; c++)
        {
            temp.clear();

            for(int r = 0; r < 9; r++)
            {   
                temp.push_back(board[r][c]);
            }

            // check for valid
            if(!isValid(temp))
                return false;
 
        }

        return true;
    }

    bool isBoxValid(int R, int C, vector<vector<char>>& board)
    {
        vector<char> temp;
        for(int r = R; r < (R+3); r++)
        {
            for(int c = C; c < (C+3); c++)
            {
                temp.push_back(board[r][c]);
            }
        }

        if(!isValid(temp))
            return false;

        return true;
    }

    bool isAllBoxesValid(vector<vector<char>>& board)
    {
        int R,C;

        for(R = 0; R < 9; R += 3)
        {
            for(C = 0; C < 9; C += 3)
            {
                if(!isBoxValid(R,C,board))
                    return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        if(!isAllRowsColumnsValid(board))
            return false;


        if(!isAllBoxesValid(board))
            return false;

        return true;
    }
};
// @lc code=end

