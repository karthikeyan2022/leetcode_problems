// This header file includes parsing the input related function definitions

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printVector(std::vector<int> nums);
void printSpaces(int count);

FILE* parseFile(char* filename);
bool parseVector(char* line, std::vector<int>& nums);

void printLinkedList(ListNode* head);
