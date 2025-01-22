class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for(int i = 0; i < nums.size(); i++)
        {
            if(visited.count(nums[i]))
                return true;
            visited.insert(nums[i]);
        }
        return false;
    }
};