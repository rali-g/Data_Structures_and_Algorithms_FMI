class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        while(maxHeap.size() > 1)
        {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if(x == y)
                continue;
            maxHeap.push(y - x);
        }
        if(!maxHeap.empty())
            return maxHeap.top();
        return 0;
    }
};