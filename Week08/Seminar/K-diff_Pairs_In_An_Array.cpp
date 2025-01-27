class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> setty;
        set<std::pair<int,int>> visited;
        int pairs = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(setty.count(nums[i] + k))
            {
                visited.insert({nums[i], nums[i] + k});
            }
            if(setty.count(nums[i] - k))
            {
                visited.insert({nums[i] - k, nums[i]});
            }
            setty.insert(nums[i]);
        }
        return visited.size();
    }
};