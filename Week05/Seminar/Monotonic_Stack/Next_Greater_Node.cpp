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
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int count(ListNode* head)
    {
        int size = 0;
        while(head)
        {
            head = head->next;
            size++;
        }
        return size;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head = reverse(head);
        int size = count(head);
        stack<int> maxMonotonicStack;
        vector<int> result(size, 0);
        for(int i = size - 1; i >= 0; i--)
        {
            while(!maxMonotonicStack.empty() && head->val >= maxMonotonicStack.top())
            {
                maxMonotonicStack.pop();
            }
            if(!maxMonotonicStack.empty())
            {
                result[i] = maxMonotonicStack.top();
            }
            maxMonotonicStack.push(head->val);
            head = head->next;
        }
        return result;
    }
};