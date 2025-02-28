class Solution {
public:
    int parents[2 * 100000];
    int find(int x)
    {
        if(parents[x] == x)
            return x;
        return parents[x] = find(parents[x]);
    }
    bool unite(int u, int v)
    {
        int parentU = find(u);
        int parentV = find(v);
        if(parentU == parentV)
            return false;
        parents[parentU] = parentV;
        return true;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i = 0; i < n; i++)
            parents[i] = i;
        int count = 0;
        for(int i = 0; i < edges.size(); i++)
        {
            unite(edges[i][0], edges[i][1]);
        }
        return !unite(source, destination);
    }
};