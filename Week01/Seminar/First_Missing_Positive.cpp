class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> visited(nums.size() + 1);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0 || nums[i] > nums.size())
                continue;
            visited[nums[i]] = true;
        }
        for(int i = 1; i <= nums.size(); i++)
        {
            if(!visited[i])
            {
                return i;
            }
        }
        return nums.size() + 1;
    }
};