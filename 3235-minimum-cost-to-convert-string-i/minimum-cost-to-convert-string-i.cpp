class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        using ll = long long;
        int n = cost.size();
        vector<vector<ll>> dp(26, vector<ll>(26, INT_MAX));
        for(int i = 0; i < cost.size(); i++)
        {
            int c1 = original[i] - 'a', c2 = changed[i] - 'a';
            dp[c1][c2] = min(dp[c1][c2], (ll)cost[i]);
        }
        for(int i = 0; i < 26; i++) dp[i][i] = 0;
        for(int middle = 0; middle < 26; middle++)
        {
            for(int from = 0; from < 26; from++)
            {
                for(int to = 0; to < 26; to++)
                {
                    dp[from][to] = min(dp[from][to], dp[from][middle] + dp[middle][to]);
                }
            }
        }
        long long res = 0;
        for(int i = 0; i < source.size(); i++)
        {
            int n1 = source[i] - 'a', n2 = target[i] - 'a';
            if(n1 == n2) continue;
            if(dp[n1][n2] >= INT_MAX) return -1;
            res += dp[n1][n2];
        }
        return res;
    }
};