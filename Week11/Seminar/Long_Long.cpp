#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int from, to, weight;
};
int main() {
    int n, m, start, end;
    std::cin >> n >> m >> start >> end;
    vector<Edge> edges(m);
    int n1, n2, w;
    for(int i = 0; i < m; i++)
    {
        std::cin >> n1 >> n2 >> w;
        edges[i] = {n1, n2, w};
    }
    
    vector<int> distances(n + 1, INT_MIN);
    distances[start] = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(auto& edge : edges)
        {
             if(distances[edge.from] != INT_MIN && distances[edge.from] + edge.weight > distances[edge.to])
             {
                 distances[edge.to] = distances[edge.from] + edge.weight;
             }
        }
    }
    for(auto& edge : edges)
    {
        if(distances[edge.from] != INT_MIN && distances[edge.from] + edge.weight > distances[edge.to])
        {
            std::cout << -1;
            return 0;
        }
    }
    if(distances[end] == INT_MIN)
    {
        std::cout << -1;
        return 0;
    }
    std::cout << distances[end];
}
