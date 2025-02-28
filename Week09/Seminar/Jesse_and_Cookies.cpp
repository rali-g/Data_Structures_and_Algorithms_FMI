#include <bits/stdc++.h>

int cookies(int k, vector<int> nums) {
    priority_queue<long long, vector<long long>, std::greater<long long>> minHeap(nums.begin(), nums.end()); 
    int iter = 0;
    while(minHeap.size() > 1)
    {
        if(minHeap.top() >= k)
            return iter;
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        minHeap.push(first + 2 * second);
        iter++;
    }
    if(!minHeap.empty() && minHeap.top() >= k)  
        return iter;
    return -1;
}