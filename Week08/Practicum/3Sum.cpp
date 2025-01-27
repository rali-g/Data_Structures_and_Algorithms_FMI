class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mappy;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            mappy[nums[i]] = i;
        }
        vector<vector<int>> tuples;
        for(int i = 0; i < n; i++)
        {
            int target = -nums[i];
            for(int j = i + 1; j < n; j++)
            {
                if(mappy.count(target - nums[j]) && mappy[target - nums[j]] > j)
                {
                    tuples.push_back({nums[i], nums[j], target - nums[j]});
                }
                j = mappy[nums[j]];               
            }
            i = mappy[nums[i]];
        }
        return tuples;
    }
};