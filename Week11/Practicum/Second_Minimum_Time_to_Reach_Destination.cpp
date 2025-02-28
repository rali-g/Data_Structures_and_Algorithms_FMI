class Solution {
public:
    unordered_map<int, unordered_set<int>> graph;
    bool hasLongerDist(int current, vector<int>& distances)
    {
        if(current == 1)
            return false;
        for(auto& neighbor : graph[current])
        {
            if(distances[neighbor] == distances[current])
            {
                return true;
            }
        }
        bool isFound = 0;
        for(auto& neighbor : graph[current])
        {
            if(distances[neighbor] == distances[current] - 1)
            {
                isFound |= hasLongerDist(neighbor, distances);
                if(isFound)
                    break;
            }
        }
        return isFound;
    } 
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> q;
        vector<int> distances(n + 1, INT_MAX);
        distances[1] = 0;
        q.push(1);
        int count = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int current = q.front();
                q.pop();
                for(auto& neighbor : graph[current])
                {
                    if(distances[neighbor] == INT_MAX)
                    {
                        distances[neighbor] = count;
                        q.push(neighbor);
                    }
                }
            }
            count++;
        }
        int edgeCount = 0;
        if(hasLongerDist(n, distances))
        {
            edgeCount = distances[n] + 1;
        }
        else
        {
            edgeCount = distances[n] + 2;
        }
        int currTime = 0;
        for(int i = 0; i < edgeCount; i++)
        {
            if((currTime / change) & 1)
            {
                currTime += change - (currTime % change);
            }
            currTime += time;
        }
        return currTime;
    }
};