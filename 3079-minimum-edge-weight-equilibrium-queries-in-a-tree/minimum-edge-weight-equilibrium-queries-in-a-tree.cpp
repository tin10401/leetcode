class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = 23;    
        graph.resize(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }    
        vector<vector<pair<int, array<int, 27>>>> dp(n, vector<pair<int, array<int, 27>>>(m, {-1, {}}));
        vector<int> depth(n);
        auto dfs = [&](int node, int par, int w, int d, auto& dfs) ->void
        {
            dp[node][0].first = par;
            dp[node][0].second[w]++;
            depth[node] = d;
            for(auto& [nei, weight] : graph[node])
            {
                if(nei != par) dfs(nei, node, weight, d + 1, dfs);
            }
        };
        dfs(0, -1, 0, 0, dfs);
        auto update = [](array<int, 27>& a, array<int, 27>& b) -> void
        {
            for(int i = 1; i <= 26; i++)
            {
                a[i] += b[i];
            }
        };

        for(int j = 1; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                auto [p, c] = dp[i][j - 1];
                if(p == -1) continue;
                dp[i][j].first = dp[p][j - 1].first;
                update(dp[i][j].second, dp[i][j - 1].second);
                update(dp[i][j].second, dp[p][j - 1].second);
            }
        }
        
        auto LCA = [&](int a, int b) -> int 
        {
            if(depth[a] > depth[b]) swap(a, b);
            int aa = a, bb = b;
            int d = depth[b] - depth[a];
            array<int, 27> total = {};
            for(int i = 0; i < m; i++)
            {
                if((d >> i) & 1)
                {
                    update(total, dp[b][i].second);
                    b = dp[b][i].first;
                }
            }
            if(a == b) 
            {
                int s = depth[bb] - depth[aa];
                int ans = s;
                for(int i = 1; i <= 26; i++) ans = min(ans, s - total[i]);
                return ans;
            } 
            for(int i = m - 1; i >= 0; i--)
            {
                if(dp[a][i].first != dp[b][i].first)
                {
                    update(total, dp[a][i].second);
                    update(total, dp[b][i].second);
                    a = dp[a][i].first;
                    b = dp[b][i].first;
                }
            }
            int x = dp[a][0].first;
            int cnt = depth[aa] + depth[bb] - 2 * depth[x];
            update(total, dp[a][0].second);
            update(total, dp[b][0].second);
            int ans = cnt;
            for(int i = 1; i <= 26; i++)
            {
                ans = min(ans, cnt - total[i]);    
            }
            return ans;
        };
        vector<int> res;
        for(auto& q : queries)
        {
            int a = q[0], b = q[1];
            res.push_back(LCA(a, b));
        }
        return res;
    }
};