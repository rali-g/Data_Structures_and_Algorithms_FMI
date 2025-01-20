class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<std::pair<int, int>> sortedNums;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            sortedNums.push_back({nums[i], i});
        }
        std::sort(sortedNums.begin(), sortedNums.end());

        int begin = 0;
        int end = sortedNums.size() - 1;
        while(begin < end)
        {
            int sum = sortedNums[begin].first + sortedNums[end].first;
            if(sum == target)
            {
                result.push_back(sortedNums[begin].second);
                result.push_back(sortedNums[end].second);
                break;
            }
            else if(sum > target)
            {
                end--;
            }
            else
            {
                begin++;
            }
        }
        return result;
    }
};