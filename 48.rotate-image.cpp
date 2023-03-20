/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
    
        int nr, nc;
        int r,c;
        int count = 4; //n*n;
        int prev;
        int curr;

        int len = n;
        int i,j;
        int off;

       
        int N = n;

        off = 0;

        // big square to smallest square traverse
        for(N = n; N > 0; N = (N-2))
        {
            // new side length of each square
            len = n - (off*2);
            
            // traverse col 0 to len0-1
            for(j = 0; j < (len-1); j++)
            {
            
                r = 0;
                c = j;
                count = 4;
                prev = matrix[r+off][c+off];
                curr = matrix[r+off][c+off];

                while(count--)
                {

                    nr = c;
                    nc = len - 1 - r;


                    prev = matrix[nr+off][nc+off];
                    matrix[nr+off][nc+off] = curr;

                    curr = prev;
                    r = nr;
                    c = nc;
                }
            }

            // IMP: offset increment at every square
            off++;
        }
        

    }
};
// @lc code=end

