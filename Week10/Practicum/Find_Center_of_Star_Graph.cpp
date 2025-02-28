class Solution {
public:
    unordered_map<int, bool> visited;
    int findCenter(vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i++)
        {
            if(visited[edges[i][0]])
                return edges[i][0];
            if(visited[edges[i][1]])
                return edges[i][1];
            visited[edges[i][0]] = true;
            visited[edges[i][1]] = true;
        }
        return -1;
    }
};