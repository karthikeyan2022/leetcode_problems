// This header file includes parsing the input related function definitions
#ifndef _PARSE_H__
#define _PARSE_H__


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>


struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <typename T>
void printVector(const std::vector<T> nums);
//declare this in header file only. otherwise giving external resolve issue.
//https://stackoverflow.com/questions/456713/why-do-i-get-unresolved-external-symbol-errors-when-using-templates
template <typename T>
void printVector(const std::vector<T> nums)
{
    //std::cout << inputstr << std::endl;       
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }

    std::cout << endl;
    
}

void printSpaces(int count);

FILE* parseFile(char* filename);

bool parseVector(char* line, std::vector<int>& nums);

void printLinkedList(ListNode* head);

FILE* parseFileByFstream(char* filename);
#endif // _PARSE_H__