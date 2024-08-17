class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        using ll = long long;
        int m = points.size(), n = points[0].size();
        ll dp[n], left[n], right[n];
        memset(dp, 0, sizeof(dp)), memset(left, 0, sizeof(left)), memset(right, 0, sizeof(right));
        ll res = *max_element(begin(points[0]), end(points[0]));
        for(int i = 0; i < n; i++) dp[i] = points[0][i];
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == 0) left[j] = dp[j];
                else left[j] = max(left[j - 1] - 1, dp[j]);
            }
            for(int j = n - 1; j >= 0; j--)
            {
                if(j == n - 1) right[j] = dp[j];
                else right[j] = max(right[j + 1] - 1, dp[j]);
            }
            for(int j = 0; j < n; j++)
            {
                dp[j] = points[i][j] + max(left[j], right[j]);
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};