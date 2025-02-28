class Solution {
public:
    struct Task{
        char ch;
        int time;
        bool operator<(const Task& other) const
        {
            return time > other.time;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<Task> minHeap;
        int minTime[26]{0};
        for(int i = 0; i < tasks.size(); i++)
        {
            minHeap.push({tasks[i], minTime[tasks[i] - 'A']});
            minTime[tasks[i] - 'A'] += (n + 1);
        }
        int currentTime = 0;
        while(!minHeap.empty())
        {
            if(currentTime < minHeap.top().time)
                currentTime = minHeap.top().time;
            minHeap.pop();
            currentTime++;
        }
        return currentTime;
    }
};