/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
class Solution {
public:

    // recursive fn to reverse single LL
    ListNode* reverseList(ListNode* node, ListNode* prev)
    {
        ListNode* head = 0;

        if(node->next == nullptr){
            head = node;
        }
        else {
            head = reverseList(node->next, node);
        }
        
        node->next = prev;
        
        return head;
    }

    void reorderList(ListNode* head) {
        
        ListNode* thead = head;

        ListNode * tmid = 0;
        ListNode * tlast = 0;

        tmid = head;
        tlast = head;

        // find the middle node (prev + currm)
        ListNode* prevmid = tmid;

        while(tlast != nullptr && tlast->next != nullptr)
        {
            // move tmid once
            prevmid = tmid;
            tmid = tmid->next;

            // move tlast twice
            tlast = tlast->next->next;
        }

        // break from the middle
        prevmid->next = nullptr;

        ListNode* tanother = reverseList(tmid, nullptr);

        ListNode* tnext1;
        ListNode* tnext2;
        ListNode* tprev = thead;
        while(thead && tanother)
        {
            tnext1 = thead->next;
            tnext2 = tanother->next;

            thead->next = tanother;
            tanother->next = tnext1;

            // prev node used to link the remaining node at last
            tprev = tanother;

            thead = tnext1;
            tanother = tnext2;
        }

        if(tanother)
            tprev->next = tanother;
              
    }
};
// @lc code=end

