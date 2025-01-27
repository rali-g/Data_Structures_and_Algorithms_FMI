class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        set<int> setty;
        for(int i = 0; i < nums.size(); i++)
        {
            setty.insert(nums[i]);
        }
        int currSequence = 1;
        int maxSequence = 1;
        for(auto& iter : setty)
        {
            if(setty.count(iter + 1))
            {
                currSequence++;
            }
            else
                currSequence = 1;
            maxSequence = max(maxSequence, currSequence);
        }
        return maxSequence;
    }
};