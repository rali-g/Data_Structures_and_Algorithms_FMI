class Solution {
public:
    struct Edge {
    int to;
    double weight;
};

struct Node {
    int index;
    double distance;

    bool operator<(const Node& other) const {
        return distance < other.distance;
    }
};
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    unordered_map<int, vector<Edge>> graph;
    for(int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
        graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    std::vector<double> distances(n, INT_MIN);
    distances[start] = 1;

    std::priority_queue<Node> nextToProcess;
    nextToProcess.push({ start, 1 });

    while (!nextToProcess.empty()) {
        auto currentNode = nextToProcess.top();
        nextToProcess.pop();

        if (currentNode.distance > distances[currentNode.index]) {
            continue;
        }

        for (const auto& edge : graph[currentNode.index]) {
            double newWeight = currentNode.distance * edge.weight;
            if (newWeight > distances[edge.to]) {
                distances[edge.to] = newWeight;
                nextToProcess.push({ edge.to, newWeight });
            }
        }
    }
    if(distances[end] == INT_MIN)
        return 0;
    return distances[end];
    }
};