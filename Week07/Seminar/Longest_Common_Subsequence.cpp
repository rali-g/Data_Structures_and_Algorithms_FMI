class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text2.size();
        int cols = text1.size();
        vector<vector<int>> dp(rows, vector<int>(cols, 1));
        bool isEqual = false;
        for(int i = 0; i < cols; i++)
        {
            if(text2[0] == text1[i])
                break;
            dp[0][i] = 0;
        }
        for(int i = 0; i < rows; i++)
        {
            if(text1[0] == text2[i])
                break;
            dp[i][0] = 0;
        }
        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < cols; j++)
            {
                if(text2[i] != text1[j])
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};