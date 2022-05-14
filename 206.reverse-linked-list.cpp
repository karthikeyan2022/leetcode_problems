/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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

#define ITER 0
#define RECUR   1
#define MODE 1

class Solution {
public:

#if(MODE==RECUR)
    ListNode* reverseLink(ListNode* curr, ListNode* prev)
    {
        // if reach end of list (null), then return prev pointer
        if(curr == 0)
            return prev;

        // store next memeber in seperte variable
        // update the reverse link
        ListNode* next = curr->next;
        curr->next = prev;

        return reverseLink(next, curr);
    }


#endif
    ListNode* reverseList(ListNode* head) {

#if(MODE==ITER)        
        ListNode* temp = head;
        ListNode* prev = 0;
        ListNode* NEXT = head;

        while(temp)
        {
            NEXT = temp->next;

            temp->next = prev;
            prev = temp;
            temp = NEXT;
        }
        return prev;
#elif(MODE==RECUR)
        return reverseLink(head, 0);
#endif

    }
};
// @lc code=end

