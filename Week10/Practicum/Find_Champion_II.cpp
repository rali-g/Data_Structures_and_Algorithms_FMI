class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int current, vector<int>& stack)
    {
        visited.insert(current);
        for(auto& neighbor : graph[current])
        {
            if(!visited.count(neighbor))
                dfs(neighbor, stack);
        }
        stack.push_back(current);
    }
    vector<int> topological_sort(int n)
    {
        vector<int> stack;
        for(int i = 0; i < n; i++)
        {
            if(!visited.count(i))
                dfs(i, stack);
        }
        std::reverse(stack.begin(), stack.end());
        return stack;
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> result = topological_sort(n);
        unordered_set<int> checked;
        checked.insert(result[0]);
        for(int i = 0; i < result.size(); i++)
        {
            if(!checked.count(result[i]))
                return -1;
            for(auto& neighbor : graph[result[i]])
            {
                checked.insert(neighbor);
            }
        }
        return result[0];
    }
};