#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Task{
    int start = 0;
    int end = 0;
    Task(int start, int end) : start(start), end(end) {}
};

struct startComparator{
    bool operator()(const Task& lhs, const Task& rhs) const 
    {
        return lhs.start > rhs.start;
    }
};

struct endComparator{
    bool operator()(const Task& lhs, const Task& rhs) const 
    {
        return lhs.end > rhs.end;
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    
    priority_queue<Task, vector<Task>, startComparator> startHeap;
    priority_queue<Task, vector<Task>, endComparator> endHeap;
    
    int first = 0, second = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin >> first >> second;
        if(first == second)
            continue;
        startHeap.push({first, second});
    }
    int maxCount = 0;
    int currTime = 0;
    while(!startHeap.empty() || !endHeap.empty())
    {
        if(endHeap.empty())
        {
            endHeap.push(startHeap.top());
            startHeap.pop();
            currTime++;
        }
        while(!startHeap.empty() && endHeap.top().end > startHeap.top().start)
        {
            endHeap.push(startHeap.top());
            startHeap.pop();
            currTime++;
        }
        maxCount = std::max(maxCount, currTime);
        if(startHeap.empty())
            break;
        while(!endHeap.empty() && startHeap.top().start >= endHeap.top().end)
        {
            endHeap.pop();
            currTime--;
        }
    }
    std::cout << maxCount;
}
