/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:

    int m = 0;
    int n = 0;
    int len = 0;

    bool wordPossible(int r, int c, int pos, vector<vector<char>>& board, 
                                             string word,
                                             vector<vector<bool>>& check)
    {
        bool bPossible = false;

        if(r < 0 || r >= m)
            return false;

        if(c < 0 || c >= n)
            return false;

        if(pos >= len)
            return false;

        // if equals and not marked
        if(board[r][c] == word[pos] && !check[r][c])
        {
            // mark
            check[r][c] = 1;
            // last word match case true;
            if(pos == len-1)
            {
                cout << "r: " << r << " c: " << c << endl;
                return true;
            }
            // 4 directions recursive
            // 1. left
            if(wordPossible(r, c-1, pos+1, board, word, check))
            {
                return true;
            }

             // 2. right
            if(wordPossible(r, c+1, pos+1, board, word, check))
            {
                return true;
            }

            // 3. top
            if(wordPossible(r-1, c, pos+1, board, word, check))
            {
                return true;
            }

            // 4. bottom
            if(wordPossible(r+1, c, pos+1, board, word, check))
            {
                return true;
            }

            check[r][c] = 0;
        }
        return bPossible;
    }


    bool exist(vector<vector<char>>& board, string word) {
        
        bool bExist = false;

        m = board.size();
        n = board[0].size();
        len = word.size();

        vector<vector<bool>> check;
        for(int i = 0; i < m; i++)
        {
           // check.push_back(0);
            vector<bool> temp;
            for(int j = 0; j < n; j++)
            {      
                temp.push_back(0);
            }

            check.push_back(temp);
        }

       // cout << board.size() << " " << board[0].size() << endl;
       // cout << check.size() << " " << check[0].size() << endl;
        for(int c = 0; c < n; c++)
        {
            for(int r = 0; r < m; r++)
            {
                if(wordPossible(r, c, 0, board, word, check))
                {
                    bExist = true;
                    break;
                }
            }
        }

        return bExist;
    }
};
// @lc code=end

