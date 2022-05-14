/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Another approach to the problem
while(interval times)
{
    reverse each time 1.2.3...
}

*/

#define DEBUG	0

#if(DEBUG)
#include<vector>
#include<iostream>
#include "parse.h"
using namespace std;
#endif


class Solution {
public:
    int betVal = 0;
    ListNode* reverseLink(ListNode* curr, ListNode* prev, int range, ListNode** SRN)
    {
        // if reach one node after right , then return prev pointer
        // also need curr pointer to get secondRightNode (for linking to first)
        if(curr == 0 || range == (betVal+1))
        {
            *SRN = curr;
            return prev;
        }
           
        // store next memeber in seperte variable
        // update the reverse link
        ListNode* next = curr->next;
        curr->next = prev;

        return reverseLink(next, curr, range+1, SRN);
    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int LEFT = left-1; // left partition before and after
        int RIGHT = right; // right partition before and after

        ListNode* firstLeft = 0;
        ListNode* firstRight = head;

        // ListNode* secondLeft = 0;
        // ListNode* secondRight = head;

        // get firstLeft and firstRight
        while(firstRight && LEFT--)
        {
            firstLeft = firstRight;
            firstRight = firstRight->next;
        }

        // get secondLeft and secondRight
        // while(secondRight && RIGHT--)
        // {
        //     secondLeft = secondRight;
        //     secondRight = secondRight->next;
        // }

        betVal = right - left + 1;

        ListNode* secondRightNode = head;
        ListNode* secondLeftNode = reverseLink(firstRight, 0, 1, &secondRightNode);

        //assert(secondLeftNode == secondLeft);
        // link first and second
        if(firstLeft)
            firstLeft->next = secondLeftNode;

        if(firstRight)
            firstRight->next = secondRightNode;
      
        // [BUG FIX] if firstLeft is null, then cant return head
        // instead return secondLeft which becomes new head  
        return (firstLeft) ? head : secondLeftNode;
    }
};


#if(DEBUG)
/*
 * Main static function 

 
 */
int main()
{
    class Solution* sol = new Solution();

    vector<int> arr = {5,4,3,2,1};

    ListNode* node; // = new ListNode(1, 0);
    ListNode* prev = 0;
    for(int a: arr)
    {
        node = new ListNode(a, prev);
        prev = node;
    }

    ListNode* head = prev;

    printLinkedList(head);

    head = sol->reverseBetween(head, 2,4);

    printLinkedList(head);

	return 0;
}
#endif
// @lc code=end

