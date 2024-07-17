class Solution {
public:
    using ll = long long;
    ll dp[100001];
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, s);
    }
    int mod = 1e9 + 7;
    ll dfs(int i, const string& s)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        ll& res = dp[i];
        if(res != -1) return res;
        res = (dfs(i + 1, s) * (s[i] == '*' ? 9 : 1)) % mod;
        if(i < s.size() - 1)
        {
            if(s[i] == '*' && s[i + 1] == '*')
            {
                res += dfs(i + 2, s) * 15;
                res %= mod;
            }
            else if(s[i] == '*')
            {
                res += dfs(i + 2, s) * (s[i + 1] <= '6' ? 2 : 1);
                res %= mod;
            }
            else if(s[i + 1] == '*')
            {
                res += dfs(i + 2, s) * (s[i] == '1' ? 9 : (s[i] == '2' ? 6 : 0));
                res %= mod;
            }
            else if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
            {
                res += dfs(i + 2, s);
                res %= mod;
            }
        }
        return res % mod;
    }
};