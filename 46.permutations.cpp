/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

#define DEBUG	1

#if(DEBUG)
#include<vector>
#include<iostream>
#include "parse.h"
using namespace std;
#endif

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {

	    vector<vector<int> > result;	    
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{

		if (begin >= num.size()) {

		    // one permutation instance
#if(DEBUG)
			cout << " --> ";
			printVector(num);
#endif		
		    result.push_back(num);
		    return;
		}

		int i;		
		for (i = begin; i < num.size(); i++) {
#if(DEBUG)			
			cout << " " << begin << " " << i << " " << "|";
#endif
			//swap values in two indices
		    swap(num[begin], num[i]);

		    permuteRecursive(num, begin + 1, result);
		    // swap back the indices
		    swap(num[begin], num[i]);
		}

#if(DEBUG)
		cout << endl;
		if(begin != 0)
		{			
			printSpaces(begin-1);
		}
#endif
    }
};


#if(DEBUG)
/*
 * Main static function 

 
 */
int main()
{
    class Solution* sol = new Solution();

    vector<int> arr = {0,1,2,3};

    vector<vector<int>> result = sol->permute(arr);

	return 0;
}

/*

SAMPLE OUTPUT FOR 0 1 2 3

0 0 | 1 1 | 2 2 | 3 3 | --> 0 1 2 3
     |     | 2 3 | 3 3 | --> 0 1 3 2
     |     |
     | 1 2 | 2 2 | 3 3 | --> 0 2 1 3
     |     | 2 3 | 3 3 | --> 0 2 3 1
     |     |
     | 1 3 | 2 2 | 3 3 | --> 0 3 2 1
     |     | 2 3 | 3 3 | --> 0 3 1 2
     |     |
     |
 0 1 | 1 1 | 2 2 | 3 3 | --> 1 0 2 3
     |     | 2 3 | 3 3 | --> 1 0 3 2
     |     |
     | 1 2 | 2 2 | 3 3 | --> 1 2 0 3
     |     | 2 3 | 3 3 | --> 1 2 3 0
     |     |
     | 1 3 | 2 2 | 3 3 | --> 1 3 2 0
     |     | 2 3 | 3 3 | --> 1 3 0 2
     |     |
     |
 0 2 | 1 1 | 2 2 | 3 3 | --> 2 1 0 3
     |     | 2 3 | 3 3 | --> 2 1 3 0
     |     |
     | 1 2 | 2 2 | 3 3 | --> 2 0 1 3
     |     | 2 3 | 3 3 | --> 2 0 3 1
     |     |
     | 1 3 | 2 2 | 3 3 | --> 2 3 0 1
     |     | 2 3 | 3 3 | --> 2 3 1 0
     |     |
     |
 0 3 | 1 1 | 2 2 | 3 3 | --> 3 1 2 0
     |     | 2 3 | 3 3 | --> 3 1 0 2
     |     |
     | 1 2 | 2 2 | 3 3 | --> 3 2 1 0
     |     | 2 3 | 3 3 | --> 3 2 0 1
     |     |
     | 1 3 | 2 2 | 3 3 | --> 3 0 2 1
     |     | 2 3 | 3 3 | --> 3 0 1 2
*/

#endif
// @lc code=end

