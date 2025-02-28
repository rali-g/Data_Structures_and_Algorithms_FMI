class Solution {
public:
    struct Comparator{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const
        {
            return p1.first < p2.first;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> minHeap;
    vector<string> findRelativeRanks(vector<int>& score) {
        for(int i = 0; i < score.size(); i++)
        {
            minHeap.push({score[i], i});
        }
        vector<string> result(score.size());
        int i = 1;
        while(!minHeap.empty())
        {
            if(i == 1)
                result[minHeap.top().second] = "Gold Medal";
            else if(i == 2)
                result[minHeap.top().second] = "Silver Medal";
            else if(i == 3)
                result[minHeap.top().second] = "Bronze Medal";
            else
            {
                result[minHeap.top().second] = std::to_string(i);
            }
            minHeap.pop();
            i++;
        }
        return result;
    }
};