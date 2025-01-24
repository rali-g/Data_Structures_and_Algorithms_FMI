class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        std::stack<int> max, min;
        max.push(INT_MIN);
        min.push(INT_MAX);
        int minIndex, maxIndex = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < max.top())
                maxIndex = i;
            else
                max.push(nums[i]);
            if(nums[n - 1 - i] > min.top())
                minIndex = n - 1 - i;
            else
                min.push(nums[n - 1 - i]);
        }
        if(maxIndex > minIndex)
            return maxIndex - minIndex + 1;
        else
            return 0;
    }
};