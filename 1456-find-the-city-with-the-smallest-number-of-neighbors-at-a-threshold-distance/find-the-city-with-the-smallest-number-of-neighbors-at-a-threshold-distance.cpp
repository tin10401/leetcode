class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> dp(n, vector<int>(n, 1e6));
        for(int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }
        for(auto& edge : edges)
        {
            dp[edge[0]][edge[1]] = edge[2], dp[edge[1]][edge[0]] = edge[2];
        }
        for(int mid = 0; mid < n; mid++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid][j]);
                }
            }
        }
        int res = 0, curr = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(dp[i][j] <= d) count++;
            }
            if(count <= curr)
            {
                curr = count;
                res = i;
            }
        }
        return res;
    }
};