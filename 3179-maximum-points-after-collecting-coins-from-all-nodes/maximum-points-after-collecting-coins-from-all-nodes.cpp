class Solution {
public:
    int dp[100001][16];
    vector<vector<int>> graph;
    vector<int> coins;
    int limit = 15;
    int dfs(int node, int par, int curr, int k)
    {
        if(curr == limit) return 0;
        int& res = dp[node][curr];
        if(res != -1) return res;
        int coin = coins[node] >> curr;
        int take = coin - k;
        for(auto& nei : graph[node])
        {
            if(nei != par) take += dfs(nei, node, curr, k);
        }
        int skip = coin >> 1;
        for(auto& nei : graph[node])
        {
            if(nei != par) skip += dfs(nei, node, curr + 1, k);
        } 
        return res = max(take, skip);
    }
     int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        memset(dp, -1, sizeof(dp));
       this->coins = coins;
       int n = coins.size();
       graph.resize(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        } 
        return dfs(0, -1, 0, k);
    }
};