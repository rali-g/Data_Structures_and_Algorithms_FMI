class Solution {
public:
    struct Edge{
        int from, to;
    };
    int parents[201];
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
        if(parentV == parentU)  
            return false;
        parents[parentU] = parentV;
        return true; 
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<Edge> edges;
        int n = isConnected.size();
        for(int i = 1; i <= n; i++)
            parents[i] = i;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    edges.push_back({i, j});
                    edges.push_back({j, i});
                }
            }   
        }
        int count = n;
        for(int i = 0; i < edges.size(); i++)
        {
            if(unite(edges[i].from, edges[i].to))
            {
                count--;

                if(count == 0)
                    break;
            }
        }
        return count;
    }
};