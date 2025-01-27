class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int score = 0;
        int maxScore = 0;
        int begin = 0;
        int end = 0;
        unordered_set<int> setty;
        while(end < n)
        {
            if(setty.count(nums[end]))
            {
                while(nums[begin] != nums[end])
                {
                    setty.erase(nums[begin]);
                    score -= nums[begin];
                    begin++;
                }
                begin++;
            }
            else
            {
                setty.insert(nums[end]);  
                score += nums[end];             
            }
            end++;
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};