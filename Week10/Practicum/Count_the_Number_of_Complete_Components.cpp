class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int current, int& nodes, int& edges)
    {
        edges += graph[current].size();
        nodes++;
        visited.insert(current);
        for(auto& neighbor : graph[current])
        {
            if(!visited.count(neighbor))
                dfs(neighbor, nodes, edges);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int completeComp = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited.count(i))
            {
                int nodes = 0;
                int edges = 0;
                dfs(i, nodes, edges);
                if(nodes * (nodes - 1) == edges)
                    completeComp++;
            }
        }
        return completeComp;
    }
};