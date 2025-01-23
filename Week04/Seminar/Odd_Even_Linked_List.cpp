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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* oddCopy = odd;
        ListNode* evenCopy = even;
        while(head && head->next)
        {
            head = head->next->next;
            if(head)
            {
                odd->next = head;
                odd = odd->next;

                even->next = head->next;
                even = even->next;
            }
            else
            {
                even->next = nullptr;
            }
        }  
        odd->next = evenCopy;
        return oddCopy;
    }
};