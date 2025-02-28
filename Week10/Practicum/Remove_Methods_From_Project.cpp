class Solution {
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> visited;
    void dfs(int current)
    {
        visited.insert(current);
        for(auto neighbor : graph[current])
        {
            if(!visited.count(neighbor))
                dfs(neighbor);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        for(int i = 0; i < invocations.size(); i++)
        {
            graph[invocations[i][0]].insert(invocations[i][1]);
        }
        dfs(k);
        vector<int> result;
        for(int i = 0; i < invocations.size(); i++)
        {
            if(visited.count(invocations[i][1]) && !visited.count(invocations[i][0]))
            {
                for(int j = 0; j < n; j++)
                    result.push_back(j);
                return result;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(!visited.count(i))
                result.push_back(i);
        }
        return result;
    }
};