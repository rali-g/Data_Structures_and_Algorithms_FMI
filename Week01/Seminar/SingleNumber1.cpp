class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            singleNumber ^= nums[i];
        }
        return singleNumber;
    }
};