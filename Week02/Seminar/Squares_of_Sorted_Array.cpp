class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int begin = 0; //negative
        int end = nums.size() - 1; //positive
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(abs(nums[begin]) > abs(nums[end]))
            {
                result[i] = nums[begin] * nums[begin];
                begin++;
            }
            else
            {
                result[i] = nums[end] * nums[end];
                end--;
            }
        }
        return result;
    }
};