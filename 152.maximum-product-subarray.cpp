/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start

#define MODE    0
class Solution {
public:
    int maxProduct(vector<int>& nums) {

#if(MODE)
        int len = nums.size();
        if(len == 1) return nums[0];
        
        int retVal = nums[0];
        int maxProduct = nums[0];
        int minProduct = nums[0];
        
        for(int i = 1; i < len; i++)
        {
            // swap if number is negative. it works actually
            if(nums[i] < 0)
                swap(maxProduct, minProduct);
            
            //cout << maxProduct << endl;
            
            // if it encounters 0, both will get reset to 0.
            maxProduct = max(nums[i], maxProduct*nums[i]);
            minProduct = min(nums[i], minProduct*nums[i]);
            
            //cout << maxProduct << endl;
            
            retVal = max(retVal, maxProduct);
        }
        
        return retVal;
#else
        int len = nums.size();
        if(len == 1) return nums[0];
        
        int retVal = INT_MIN;
        int product = 1;
        
        // inorder to capture odd -ve numbers, traverse left to right and right to left.
        // if nums[i]  is 0 reset the product to 1; contiguous subarray break
        
        // from left to right. though -ve numbers are present;
        
        for(int i = 0; i < len; i++)
        {
            product = product * nums[i];
            
            retVal = max(retVal, product);
            
            cout << retVal << endl;
            
            if(product == 0)
                product = 1;
        }
        
        product = 1;
        for(int i = len-1; i >= 0; i--)
        {
            product = product * nums[i];
            
            retVal = max(retVal, product);
            
            if(product == 0)
                product = 1;
        }
        

        
        return retVal;
#endif
    }
};
// @lc code=end

