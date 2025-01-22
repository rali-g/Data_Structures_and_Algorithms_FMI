class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> counter(nums.size() + 1);
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(++counter[nums[i]] == 2)
                result.push_back(nums[i]);
        }
        return result;
    }
};