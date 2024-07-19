class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> vis(n, vector<bool>(n));
        int count[n];
        memset(count, 0, sizeof(count));
        for(auto& edge : edges)
        {
            int u = edge[0] - 1, v = edge[1] - 1;
            count[u]++;
            count[v]++;
            vis[u][v] = vis[v][u] = true;
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j]) continue;
                for(int k = 0; k < n; k++)
                {
                    if(vis[i][j] && vis[i][k] && vis[j][k])
                    {
                        res = min(res, count[i] + count[j] + count[k] - 6);
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};