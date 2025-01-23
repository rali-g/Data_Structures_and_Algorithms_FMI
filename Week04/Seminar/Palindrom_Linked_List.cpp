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
    int length(ListNode* head)
    {
        ListNode* iter = head;
        int length = 0;
        while(iter)
        {
            iter = iter->next;
            length++;
        }
        return length;
    }
    bool isPalindrome(ListNode* head) {
        int size = length(head);
        ListNode* curr = head;
        for(int i = 0; i < size / 2; i++)
        {
            curr = curr->next;
        }
        ListNode* reversedHead = reverse(curr);
        curr = head;
        for(int i = 0; i < size / 2; i++)
        {
            if(curr->val != reversedHead->val)
                return false;
                curr = curr->next;
                reversedHead = reversedHead->next;
        }
        return true;
    }
};