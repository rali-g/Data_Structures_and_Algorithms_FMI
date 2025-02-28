class Solution {
public:
    unordered_map<int, vector<int>> graph;
    bool dfs(unordered_map<int, vector<int>>& graph, unordered_map<int, int>& colours, 
    int current, vector<int>& st)
    {
        colours[current] = 1;
        for(auto& neighbor : graph[current])
        {
            if(colours[neighbor] == 1)
                return true;
            if(colours[neighbor] == 2)
                continue;
            if(dfs(graph, colours, neighbor, st))
                return true;
        }
        st.push_back(current);
        colours[current] = 2;
        return false;
    }
    vector<int> topological_sort(unordered_map<int, vector<int>>& graph, int numCourses)
    {
        unordered_map<int, int> colours;
        vector<int> st;
        for(int i = 0; i < numCourses; i++)
        {
            if(colours[i] != 0)
                continue;
            if(dfs(graph, colours, i, st))
                return {};
        }
        return st;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return topological_sort(graph, numCourses);
    }
};