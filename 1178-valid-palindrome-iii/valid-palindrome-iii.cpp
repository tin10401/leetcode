class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        string ss = string(rbegin(s), rend(s));
        int dp[2][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(s[i - 1] == ss[j - 1])
                {
                    dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
                }
                else
                {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return (s.size() - dp[n % 2][n]) <= k;
    }
};