class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mappy;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mappy.count(target - nums[i]))
            {
                return {i, mappy[target - nums[i]]};
            }
            mappy[nums[i]] = i;
        }
        return {};
    }
};