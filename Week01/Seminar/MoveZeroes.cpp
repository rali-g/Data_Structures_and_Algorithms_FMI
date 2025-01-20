class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int freeIndex = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[freeIndex] = nums[i];
                freeIndex++;
            }
        }
        for(; freeIndex < nums.size(); freeIndex++)
        {
            nums[freeIndex] = 0;
        }
    }
};