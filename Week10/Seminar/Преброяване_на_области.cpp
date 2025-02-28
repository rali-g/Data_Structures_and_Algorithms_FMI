#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int current)
{
    visited.insert(current);
    
    for(auto& neighbor : graph[current])
    {
        if(!visited.count(neighbor))
        {
            visited.insert(neighbor);
            dfs(graph, visited, neighbor);
        }
    }
}

int main() {
    int q = 0;
    std::cin >> q;
    for(int i = 0; i < q; i++)
    {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> visited;
        int nodes = 0, edges = 0;
        int first = 0, second = 0; 
        std::cin >> nodes >> edges;
        for(int i = 0; i < edges; i++)
        {
            std::cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        int count = 0;
        for(int i = 0; i < nodes; i++)
        {
            if(!visited.count(i))
            {
                dfs(graph, visited, i);
                count++;
            }
        }
        std::cout << count << " ";
    }
}
