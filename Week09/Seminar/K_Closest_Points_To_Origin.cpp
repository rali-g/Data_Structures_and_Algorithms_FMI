class Solution {
    struct Comparator
    {
        bool operator()(const vector<int>& first, const vector<int>& second) const
        {
            return first[0]*first[0] + first[1]*first[1] > second[0]*second[0] + second[1]*second[1];
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, Comparator> distHeap(points.begin(), points.end());
        for(int i = 0; i < k; i++)
        {
            result.push_back(distHeap.top());
            distHeap.pop();
        }
        return result;
    }
};