class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        int n = costs.size();
        vector<int> dp(n);
        dp[0] = costs[0];
        dp[1] = costs[1];
        for(int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i - 2], dp[i - 1]) + costs[i];
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};