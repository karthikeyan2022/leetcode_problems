
#define DEBUG   1

#if(DEBUG)
#include<iostream>
#include<vector>
#include "parse.h"
using namespace std;
#endif


class Solution {
public:
    vector<int> maximumEvenSplit(long long finalSum) {
        
        vector<int> retVect;
        
        if(finalSum % 2)
            return retVect;
        
        long long i = 2;
        while(finalSum > 0)
        {
            //cout << i << " " << finalSum << endl;
            // (16 - 8) < (8+2)
            // since next subtraction finalsum is lesser than next even number(10), we will run into duplicate
            // even number
            if((finalSum - i) < (i+2))
            {
                break;
            }
            
            retVect.push_back(i);
            finalSum -= i;
            
            i = i+2;
        }
        
        // push back the remaining number (it will be even)
        retVect.push_back(finalSum);
        
        return retVect;    
    }
};

#if(DEBUG)

int main()
{
    class Solution* sol = new Solution();


    vector<int> ret = sol->maximumEvenSplit(28);

    printVector(ret);
}
#endif