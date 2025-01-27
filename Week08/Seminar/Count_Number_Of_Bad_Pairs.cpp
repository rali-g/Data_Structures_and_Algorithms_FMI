class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long goodPairs = 0;
        long long allPairs = n * (n - 1) / 2;
        unordered_map<long long, long long> mappy;
        for(int i = 0; i < n; i++)
        {
            mappy[nums[i] - i]++;
        }
        for(auto& iter : mappy)
        {
            goodPairs += iter.second * (iter.second - 1) / 2;
        }
        return allPairs - goodPairs;
    }
};