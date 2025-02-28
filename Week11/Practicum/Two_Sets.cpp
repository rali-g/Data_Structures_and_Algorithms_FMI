#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long weight;
};

struct Node {
    int node;
    long long distance;
    bool operator<(const Node& rhs) const {
        return distance > rhs.distance;
    }
};

unordered_map<int, vector<Edge>> graph;
priority_queue<Node> nextToProcess;
int main() {
    int n = 0;
    int m = 0;
    int n1, n2, w = 0;
    std::cin >> n >> m;
    vector<long long> distances(n, LLONG_MAX);
    
    for(int i = 0; i < m; i++)
    {
        std::cin >> n1 >> n2 >> w;
        graph[n1].push_back({n2, w});
        graph[n2].push_back({n1, w});       
    }
    int k = 0;
    std::cin >> k;
    for(int i = 0; i < k; i++)
    {
        int curr = 0;
        std::cin >> curr;
        distances[curr] = 0;
        nextToProcess.push({curr, 0});
    }
    int q = 0;
    std::cin >> q;
    vector<int> sNodes(q);
    for(int i = 0; i < q; i++)
    {
        std::cin >> sNodes[i];
    }
    while(!nextToProcess.empty())
    {
        Node current = nextToProcess.top();
        nextToProcess.pop();
        if(current.distance > distances[current.node])
            continue;
        for(auto& edge : graph[current.node])
        {
            int newWeight = edge.weight + current.distance;
            if(newWeight < distances[edge.to])
            {
                distances[edge.to] = newWeight;
                nextToProcess.push({edge.to, newWeight});
            }
        }
    }
    for(int i = 0; i < q; i++)
    {
        std::cout << distances[sNodes[i]] << "\n";
    }
}
