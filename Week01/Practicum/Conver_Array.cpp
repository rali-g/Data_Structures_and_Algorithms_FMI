class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int histogram[201];
        for(int i = 1; i < 201; i++)
        {
            histogram[i] = -1;
        }
        int rows = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            rows = max(rows, ++histogram[nums[i]]);
        }
        rows++;
        vector<vector<int>> result(rows);
        for(int i = 0; i < nums.size(); i++)
        {
            result[histogram[nums[i]]--].push_back(nums[i]);
        }
        return result;
    }
};