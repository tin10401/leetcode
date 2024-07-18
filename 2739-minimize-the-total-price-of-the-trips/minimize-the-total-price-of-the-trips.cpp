class Solution {
public:
    vector<vector<int>> graph;
    vector<int> count, price;
    void dfs(int start, int par, int end, vector<int>& curr)
    {
        if(start == end)
        {
            for(auto& node : curr)
            {
                count[node]++;
            }
            return;
        }
        for(auto& nei : graph[start])
        {
            if(nei != par)
            {
                curr.push_back(nei);
                dfs(nei, start, end, curr);
                curr.pop_back();
            }
        }
    }

    int dp[51][2];

    int compute(int node, bool prev, int par)
    {
        int& res = dp[node][prev];
        if(res != -1) return res;
        int skip = count[node] * price[node];
        int take = count[node] * price[node] / 2;
        for(auto& nei : graph[node])
        {
            if(nei == par) continue;
            skip += compute(nei, false, node);
        }
        if(prev) return res = skip;
        for(auto& nei : graph[node])
        {
            if(nei == par) continue;
            take += compute(nei, true, node);
        }
        return res = min(skip, take);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        memset(dp, -1, sizeof(dp));
        graph.resize(n), count.resize(n);
        this->price = price;
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(auto& it : trips)
        {
            vector<int> curr = {it[0]};
            dfs(it[0], -1, it[1], curr);
        }
        return compute(0, 0, -1);
    }
};