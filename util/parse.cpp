#include "parse.h"

void printVector(std::vector<int> nums)
{
    //std::cout << inputstr << std::endl;       
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }

    //std::cout << std:: endl;
    
}


void printSpaces(int count)
{
    while(count--) {std::cout << "     |";}
}

