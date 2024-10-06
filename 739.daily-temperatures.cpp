/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start

#define DEBUG 0
#if(DEBUG)
#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;
#endif

struct node
{
    int val;
    int idx;
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> days;

        stack<node*> tempstack;
        int len = temperatures.size();

        // Traverse the temperatures from last to first
        for(int i = len-1; i >= 0; i--)
        {
            // 1.) if stack's top val temperature is less than traversing temp value, then pop it. Keep doing it
            while((tempstack.empty() == false) && (tempstack.top()->val <= temperatures[i]))
            {
                tempstack.pop();
            }

            // 2.) Find the day interval - [top-idx - traversing-temp-idx]
            if(tempstack.empty())
            {
                days.push_back(0);
            }
            else
            {
                days.push_back(tempstack.top()->idx - i);
            }

            // 3.) Push the traversing temp to the stack
            struct node* nnode = new node();
            nnode->idx = i;
            nnode->val = temperatures[i];

            tempstack.push(nnode);
        }
        
        reverse(days.begin(), days.end());
        return days;

    }
};


#if(DEBUG)
int main()
{

}
#endif
// @lc code=end

