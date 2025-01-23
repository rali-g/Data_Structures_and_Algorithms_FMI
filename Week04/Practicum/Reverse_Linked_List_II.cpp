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
    ListNode* reverse(ListNode* head)
    {
        if(!head)
            return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* previous = nullptr;
        ListNode* curr = head;
        for(int i = 0; i < left - 1; i++)
        {
            previous = curr;
            curr = curr->next;
        }

        ListNode* currCopy = curr;
        for(int i = 0; i < right - left; i++)
        {
            currCopy = currCopy->next;
        }

        ListNode* next = currCopy->next;
        currCopy->next = nullptr;

        ListNode* reversedHead = reverse(curr);

        curr->next = next;

        if(previous)
            previous->next = reversedHead;
        else
            return reversedHead;

        return head;
    }
};