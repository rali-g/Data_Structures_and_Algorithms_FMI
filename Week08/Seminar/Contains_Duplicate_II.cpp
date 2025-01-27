class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mappy;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mappy.count(nums[i]) && abs(mappy[nums[i]] - i) <= k)
                return true;
            mappy[nums[i]] = i;
        }
        return false;
    }
};