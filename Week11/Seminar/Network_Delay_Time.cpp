class Solution {
public:
    struct Node
    {
        int node, distance;
        bool operator<(const Node& other) const
        {
            return distance > other.distance;
        }
    };
    struct Edge
    {
        int to, weight;
    };
    unordered_map<int, vector<Edge>> graph;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i = 0; i < times.size(); i++)
        {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<Node> nextToProcess;
        nextToProcess.push({k, 0});
        vector<int> distances(n + 1, INT_MAX);
        distances[k] = 0;
        
        while(!nextToProcess.empty())
        {
            Node current = nextToProcess.top();
            nextToProcess.pop();

            if(current.distance > distances[current.node])
                continue;
            for(auto& edge : graph[current.node])
            {
                int newWeight = current.distance + edge.weight;
                if(newWeight < distances[edge.to])
                {
                    distances[edge.to] = newWeight;
                    nextToProcess.push({edge.to, newWeight});
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(distances[i] == INT_MAX)
                return -1;
        }
        distances.erase(distances.begin() + k);
        return *max_element(distances.begin() + 1, distances.end());
    }
};