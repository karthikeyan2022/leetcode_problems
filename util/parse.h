// This header file includes parsing the input related function definitions

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

void printVector(std::vector<int> nums);
void printSpaces(int count);

FILE* parseFile(char* filename);
bool parseVector(char* line, std::vector<int>& nums);
