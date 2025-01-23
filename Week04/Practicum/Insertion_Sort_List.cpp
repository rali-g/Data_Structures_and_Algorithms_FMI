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
    ListNode* insert(ListNode* head, ListNode* element)
    {
        ListNode* result = head;
        ListNode* prev = nullptr;
        while(head)
        {
            if(head->val >= element->val)
            {
                if(!prev)
                {
                    element->next = head;
                    result = element;
                    return result;
                }
                prev->next = element;
                element->next = head;
                return result;
            }
            prev = head;
            head = head->next;
        }
        return result;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return head;
        ListNode* result = head;
        ListNode* prev = head;
        head = head->next;
        while(head)
        {
            ListNode* next = head->next;
            if(head->val < prev->val)
            {
                prev->next = head->next;
                result = insert(result, head);
                head = next;
            }
            else
            {
                prev = head;
                head = head->next;
            }
        }
        return result;
    }
};