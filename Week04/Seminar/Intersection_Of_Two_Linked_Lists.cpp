/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1 = length(headA);
        int size2 = length(headB);
        int diff = abs(size1 - size2);
        if(size1 < size2)
        {
            for(int i = 0; i < diff; i++)
            {
                headB = headB->next;
            }
        }
        else if(size1 > size2)
        {
            for(int i = 0; i < diff; i++)
            {
                headA = headA->next;
            }
        }
        while(headA)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};