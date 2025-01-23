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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        for(int i = 0; i < lists.size(); i++)
        {
            auto iter = lists[i];
            while(iter)
            {
                minHeap.push(iter->val);
                iter = iter->next;
            }
        }
        if(minHeap.empty())
            return nullptr;
        ListNode* result = new ListNode(minHeap.top());
        minHeap.pop();
        ListNode* iter = result;
        while(!minHeap.empty())
        {
            iter->next = new ListNode(minHeap.top());
            minHeap.pop();
            iter = iter->next;
        }
        return result;
    }
};