class Solution {
public:
    struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ (h2 << 1);
        }
    };
    struct Node{
        int x, y;
        int distance;
        bool operator<(const Node& other) const
        {
            return distance > other.distance;
        }
    };
    int getCost(int x1, int y1, int x2, int y2)
    {
        return abs(x2 - x1) + abs(y2 - y1);
    }
    priority_queue<Node> nextToProcess;
    unordered_map<std::pair<int, int>, int, pair_hash> distances;
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        nextToProcess.push({start[0], start[1], 0});
        distances[{start[0], start[1]}] = 0;
        while(!nextToProcess.empty())
        {
            Node current = nextToProcess.top();
            nextToProcess.pop();
            if(distances.count({current.x, current.y}) && 
            current.distance > distances[{current.x, current.y}])
                continue;
            for(auto& edge : specialRoads)
            {
                int newWeight = current.distance + 
                getCost(current.x, current.y, edge[0], edge[1]) + edge[4];
                if (!distances.count({edge[2], edge[3]}) || newWeight < distances[{edge[2], edge[3]}])
                {
                    distances[{edge[2], edge[3]}] = newWeight;
                    nextToProcess.push({edge[2], edge[3], newWeight});
                }
            }
            //add direct line to finish
            int newWeight = current.distance + getCost(current.x, current.y, target[0], target[1]);
            if (!distances.count({target[0], target[1]}) || newWeight < distances[{target[0], target[1]}])
            {
                distances[{target[0], target[1]}] = newWeight;
            }
        }
        return distances[{target[0], target[1]}];
    }
};