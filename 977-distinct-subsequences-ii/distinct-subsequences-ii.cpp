class Solution {
public:
    int mod = 1e9 + 7;
    using ll = long long;
    ll dp[2001];
    ll dfs(int start, const string& s)
    {
        if(start == s.size()) return 1;
        ll& res = dp[start];
        if(res != -1) return res;
        res = 2 * dfs(start + 1, s);
        for(int i = start + 1; i < s.size(); i++)
        {
            if(s[i] == s[start])
            {
                res -= dfs(i + 1, s);
                break;
            }
        }
        return res % mod;
    }
    int distinctSubseqII(string s) {
        memset(dp, -1, sizeof(dp));
        return (dfs(0, s) - 1 + mod) % mod;
    }
};