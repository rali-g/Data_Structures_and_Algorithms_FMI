class Solution {
public:
    unordered_map<int, bool> colors;
    unordered_map<int, vector<int>> graph;
    bool dfs(unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& colors, 
    int current, bool currentColor = true)
    {
        if(colors.find(current) != colors.end())
            return colors[current] == currentColor;
        colors[current] = currentColor;
        for(auto& neighbor : graph[current])
        {
            if(!dfs(graph, colors, neighbor, !currentColor))
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i = 0; i < dislikes.size(); i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(colors.find(i) == colors.end())
            {
                if(!dfs(graph, colors, i))
                    return false;
            }
        }
        return true;
    }
};