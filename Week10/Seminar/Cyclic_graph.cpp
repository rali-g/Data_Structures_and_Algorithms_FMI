#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool dfs(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& colours, int current)
{
    colours[current] = 1;
    for(auto& neighbor : graph[current])
    {
        if(colours[neighbor] == 1)
            return true;
        if(colours[neighbor] == 2)
            continue;
        if(dfs(graph, colours, neighbor))
            return true;
            
    }
    colours[current] = 2;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    int n = 0;
    std::cin >> n;
    int nodes = 0, edges = 0;
    int first = 0, second = 0, weight = 0;
    for(int i = 0; i < n; i++)
    {
        unordered_map<int, vector<int>> graph;
        std::cin >> nodes >> edges;
        for(int j = 0; j < edges; j++)
        {
            std::cin >> first >> second >> weight;
            graph[first].push_back(second);
        }
        unordered_map<int, int> colours;
        bool cycleFound = 0;
        for(int i = 1; i <= nodes; i++)
        {
            if(colours[i] != 0)
                continue;
            if(dfs(graph, colours, i))
            {
                    cycleFound = 1; 
                        break;
            }
        }
        std::cout << boolalpha << cycleFound << " ";
    }
}
