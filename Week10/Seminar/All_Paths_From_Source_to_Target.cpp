class Solution {
public:
    unordered_map<int, unordered_set<int>> graph;
    void dfs(int current, vector<vector<int>>& result,
    vector<int> path, int target)
    {
        path.push_back(current);
        if(current == target)
            result.push_back(path);
        for(auto neighbor : graph[current])
        {
            dfs(neighbor, result, path, target);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                graph[i].insert(nums[i][j]);
            }
        }
        vector<vector<int>> result;
        dfs(0, result, {}, nums.size() - 1);
        return result;
    }
};