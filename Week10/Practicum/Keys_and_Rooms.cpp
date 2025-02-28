class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    void dfs(int current, int target)
    {
        visited.insert(current);
        for(auto& neighbor : graph[current])
        {
            if(!visited.count(neighbor))
                dfs(neighbor, target);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int nodes = rooms.size();
        for(int i = 0; i < rooms.size(); i++)
        {
            for(int j = 0; j < rooms[i].size(); j++)
            {
                graph[i].push_back(rooms[i][j]);
            }
        }
        dfs(0, nodes - 1);
        for(int i = 0; i < nodes; i++)
        {
            if(!visited.count(i))
                return false;
        }
        return true;
    }
};