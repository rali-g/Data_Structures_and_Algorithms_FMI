class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        queue<int> q;
        int sum = 0;
        int maxSum = 0;
        for(int i = 0; i < k; i++)
        {
            q.push(nums[i]);
            sum += nums[i];
        }
        maxSum = sum;
        for(int i = k; i < nums.size(); i++)
        {
            sum -= q.front();
            q.pop();
            q.push(nums[i]);
            sum += nums[i];
            if(maxSum < sum)
                maxSum = sum;
        }
        return maxSum / (double)k;
    }
};