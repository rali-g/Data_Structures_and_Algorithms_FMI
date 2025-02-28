#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<queue>
#include <climits>
using namespace std;

struct Edge{
    int to;
    long long weight;
};

struct Node{
    int node;
    long long distance;
    bool operator<(const Node& other) const
    {
        return distance > other.distance;
    }
};

const long long UPPER_BOUND = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nodes = 0;
    int edges = 0;
    std::cin >> nodes >> edges;
    unordered_map<int, vector<Edge>> graph;
    priority_queue<Node> nextToProcess;
    vector<long long> distances(nodes + 1, LLONG_MAX);
    vector<long long> ways(nodes + 1, 0);
    
    long long n1, n2, w = 0;
    for(int i = 0; i < edges; i++)
    {
        std::cin >> n1 >> n2 >> w;
        graph[n1].push_back({n2, w});
    }
    nextToProcess.push({1, 0});
    distances[1] = 0;
    ways[1] = 1;

    while(!nextToProcess.empty())
    {
        Node current = nextToProcess.top();
        nextToProcess.pop();

        for(auto& edge : graph[current.node])
        {
            long long newWeight = edge.weight + current.distance;
            if(newWeight < distances[edge.to])
            {
                distances[edge.to] = newWeight;
                nextToProcess.push({edge.to, newWeight});
                ways[edge.to] = ways[current.node];
            }
            else if (newWeight == distances[edge.to])
            {
                ways[edge.to] = (ways[edge.to] + ways[current.node]) % UPPER_BOUND;
            }
        }
    }
    if(distances[nodes] == LLONG_MAX)
    {
        std::cout << -1 << " " << 0;
        return 0;
    }
    std::cout << distances[nodes] << " " << ways[nodes];
}
