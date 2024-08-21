class Solution {
public:
    int dp[101][101];
    string s;
    int dfs(int left, int right)
    {
        if(left >= right) return 1;
        int &res = dp[left][right];
        if(res != -1) return res;
        res = INT_MAX;
        for(int i = left; i < right; i++)
        {
            res = min(res, dfs(left, i) + dfs(i + 1, right));
        }
        res -= s[left] == s[right];
        return res;
    }
    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        this->s = s;
        return dfs(0, s.size() - 1);
    }
};