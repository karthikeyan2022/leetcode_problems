/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

#define MODE 0

class Solution {
public:
    int maxArea(vector<int>& height) {

 #if(MODE)

        //ACCEPTED BUT TOO LONG       
        int len = height.size();
        int currMaxLeft = 0;
        int currMaxRight = 0;
        
        int maxVal = 0;
        
        for(int i = 0; i < len; i++)
        {   
            // if already left max height is obtained no need to check;
            if(currMaxLeft >= height[i]) continue;
            
            currMaxLeft = max(currMaxLeft, height[i]);
            
            currMaxRight = 0;
            
            for(int j = len-1; j > i; j--)
            {          
                // if already right max height is obtained no need to check;     
                if(currMaxRight >= height[j]) continue;
                
                currMaxRight = max(currMaxRight, height[j]);
                           
                maxVal = max(maxVal, min(height[i], height[j])* (j-i));
            }
            
        }
           
        return maxVal;
#else
    // TWO POINTER EFFICIENT SOLUTION

    int left = 0;
    int right = height.size()-1;

    int width;
    int maxVal = 0;
    while(left < right)
    {
        width = right - left;

        maxVal = max(maxVal, min(height[left],height[right]) * width);


        // update right or left pointer
        // left is smaller means try to find bigger moving forward leftp
        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxVal;


#endif
    }
};
// @lc code=end

