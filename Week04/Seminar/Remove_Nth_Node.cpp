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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next || !head)
            return nullptr;
        int size = length(head);
        int target = size - n - 1;
        if(n == size)
        {
            head = head->next;
            return head;
        }
        ListNode* result = head;
        for(int i = 0; i < target; i++)
        {
            head = head->next;
        }
        head->next = head->next->next;
        return result;
    }
};