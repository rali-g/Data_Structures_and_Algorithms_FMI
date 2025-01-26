class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            int min = INT_MAX;
            for(int j = 0; j < n; j++)
            {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1)
                {
                    if(dp[i - coins[j]] < min)
                        min = dp[i - coins[j]];
                }
            }
            if(min != INT_MAX)
                dp[i] = min + 1;
        }
        return dp[amount];
    }
};