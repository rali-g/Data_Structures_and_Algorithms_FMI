class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int targetCount = nums.size() / 3;
        std::sort(nums.begin(), nums.end());
        vector<int> result;
        int currCount = 0;
        int current = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == current)
            {
                currCount++;
            }
            else
            {
                if(currCount >= targetCount)
                    result.push_back(current);
                current = nums[i];
                currCount = 0;
            }
        }
        if(currCount >= targetCount)
            result.push_back(current);
        return result;
    }
};