
#include "parse.h"

using namespace std;


void printSpaces(int count)
{
    while(count--) {std::cout << "     |";}
}

FILE* parseFile(char* filename)
{
    string inputFileName = filename;
    FILE *fp = NULL;

    cout << inputFileName << endl;

    size_t spos = inputFileName.find("exe");
    inputFileName[spos]   = 't';
    inputFileName[spos+1] = 'x';
    inputFileName[spos+2] = 't';
    
    fp = fopen(inputFileName.c_str(), "r");

    if (fp == NULL)
    {
		fprintf(stderr, "input file %s not found.  Exiting.\n", inputFileName.c_str());
		exit(-1);
	}

    return fp;
    
   


    //fclose(fp);
}

bool parseVector(char* line, std::vector<int>& nums)
{
    int c = 0;
     
    if(line[0] == '\0' || line[0] != '[')
    {
        std::cout << "Check input txt file!!!" << std::endl;
        return 0;
    }

    c = 1;
    char number[100]; 
    number[0] = '\0';
    int s = 0;
    while(line[c] != '\0')
    {
        std::cout << line[c];;

        // if delim is found and number is already filled
        if((line[c] == ',' || line[c] == ']') && number[0] != '\0')
        {
            number[s] = '\0';

            nums.push_back(atoi(number));

            // reset s 
            s = 0;
            c++;
            continue;
        }
       
        // fill the number
        number[s++] = line[c++];
        
    }

    

    return 1;
}


void printLinkedList(ListNode* head)
{
    cout << "Linked list : ";
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

FILE* parseFileByFstream(char* filename)
{
    fstream inputfile;

    string inputFileName = filename;
    FILE *fp = NULL;

    cout << inputFileName << endl;

    string sample = inputFileName;
    sample.erase(sample.end()-3, sample.end());
    cout << sample << endl;
    
    size_t spos = inputFileName.find("exe");
    inputFileName[spos]   = 't';
    inputFileName[spos+1] = 'x';
    inputFileName[spos+2] = 't';
    
    fp = fopen(inputFileName.c_str(), "r");

    if (fp == NULL)
    {
		fprintf(stderr, "input file %s not found.  Exiting.\n", inputFileName.c_str());
		exit(-1);
	}

    return fp;
}