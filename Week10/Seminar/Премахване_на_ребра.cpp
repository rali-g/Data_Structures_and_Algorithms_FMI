#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int result = 0;
unordered_map<int, unordered_set<int>> graph;
int dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int current)
{
    if(graph[current].size() == 0)
        return 1;
    visited.insert(current);
    int children = 1;
    for(auto& neighbor : graph[current])
    {
        if(!visited.count(neighbor))
        {
            children += dfs(graph, visited, neighbor);
        }
    }
    
    if(children % 2 == 0)
    {
        result++;
        return 0;
    }
    return children;
}

int main() {
    int nodes = 0;
    int edges = 0;
    std::cin >> nodes >> edges;
    int first = 0;
    int second = 0;
    for(int i = 0; i < edges; i++)
    {
        std::cin >> first >> second;
        graph[first].insert(second);
        graph[second].insert(first);
    }
    unordered_set<int> visited;
    dfs(graph, visited, 1);
    std::cout << result - 1;
}
