/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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

#define DEBUG   0

#if(DEBUG)
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif  

class Solution {
public:

    int getListSize(ListNode* tranode)
    {
        int count = 0;

        while(tranode)
        {
            count++;
            tranode = tranode->next;
        }

        return count;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int len1 = getListSize(l1);
        int len2 = getListSize(l2);    

        int maxlen = len1;
        ListNode* curr = l1;
        ListNode* prev = nullptr; 

        int carry = 0;
        int num = 0;

        if(len2 > len1) 
        {
            curr = l2;
            maxlen = len2;
        }

        ListNode* retnode = curr;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        // while(temp1 != nullptr && temp2 != nullptr)
        while(maxlen--)
        {
            // 1. calculate num
            //1.1 init num
            num = 0;

            //1.2 accumulate it
            if(temp1) {num+=temp1->val;}

            if(temp2) {num+=temp2->val;}

            //1.3 add carry if in case    
            num += carry;

            // 1.4 adjust num if overflows
            if(num > 9) 
            {
                carry = 1;
                num = num % 10;
            }
            else
            {
                carry = 0; 
            }

            // assign the value of num to final linked list
            curr->val = num;


            prev = curr;
            curr = curr->next;

            if(temp1)    
                temp1 = temp1->next;
            
            if(temp2)
                temp2 = temp2->next;
        
        } // end of while loop

        // if remaining carry is present create new node and append
        if(carry)
        {
            if(prev)
                prev->next = new ListNode(1, nullptr);
        }

        return retnode;
    
    }
};

#if(DEBUG)
int main()
{
    class Solution* sol = new Solution();

    ListNode* nodes[10];
    int arr1[3] = {2,4,3}; 
    int arr2[3] = {5,6,4};

    ListNode* prev = nullptr;

    for (int i = 0; i < 3; i++)
    {
        nodes[i] = new ListNode(arr1[i], prev);

        prev = nodes[i];
    }

    prev = nullptr;

    for (int i = 3; i < 6; i++)
    {
        /* code */
        nodes[i] = new ListNode(arr2[i-3], prev);

        prev = nodes[i];
    }
    
    ListNode* l1 = nodes[2];
    ListNode* l2 = nodes[5];
    ListNode* retnode = sol->addTwoNumbers(l1,l2);

}
#endif
// @lc code=end

