class Solution {
public:
    int dp[101][101];
    int dfs(int index, int k, const string& s)
    {
        if(index == s.size()) return k == 0 ? 0 : 1e9;
        if(k == 1) return palin[index][s.size() - 1];
        int& res = dp[index][k];
        if(res != -1) return res;
        res = INT_MAX;
        for(int i = index; i < s.size(); i++)
        {
            res = min(res, palin[index][i] + dfs(i + 1, k - 1, s));
        }
        return res;
    }
    vector<vector<int>> palin;
    int palindromePartition(string s, int k) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        palin.assign(n, vector<int>(n));
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
        return dfs(0, k, s);
    }
};