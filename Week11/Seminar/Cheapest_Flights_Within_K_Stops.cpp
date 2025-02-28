class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<int> distances(n, INT_MAX);
        distances[src] = 0;
        for(int i = 0; i <= k; i++)
        {
            vector<int> previous(distances);
            for(auto& edge : edges)
            {
                if(distances[edge[0]] != INT_MAX && distances[edge[0]] + edge[2] < previous[edge[1]])
                {
                    previous[edge[1]] = distances[edge[0]] + edge[2];
                }
            }
            distances = std::move(previous);
        }
        if(distances[dst] == INT_MAX)
            return -1;
        return distances[dst];
    }
};