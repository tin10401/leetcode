class Solution {
public:
    
    int palindromePartition(string s, int k) {
        int n = s.size();
        int dp[101][101], palin[101][101];
        memset(palin, 0, sizeof(palin));
        for(int i = 0; i < 101; i++) fill(dp[i], dp[i] + 101, 1e9);
        dp[0][k] = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i - 1, k = i + 1; j >= 0 && k < n; j--, k++)
            {
                palin[j][k] = palin[j + 1][k - 1] + (s[j] != s[k]);
            }
            int prev = 0;
            for(int j = i, k = i + 1; j >= 0 && k < n; j--, k++)
            {
                palin[j][k] = prev + (s[j] != s[k]);
                prev = palin[j][k];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                for(int K = k - 1; K >= 0; K--)
                {
                    dp[j + 1][K] = min(dp[j + 1][K], dp[i][K + 1] + palin[i][j]);
                }
            }
        }

        return dp[n][0];
    }
};