class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    int n;
    int dfs(int source, int k)
    {
        priority_queue<array<int, 4>> maxHeap;
        int dp[51][16] = {};
        int m = ((1 << n) - 1) & (~(1 << source));
        maxHeap.push({0, source, k, m});
        int res = INT_MIN;
        while(!maxHeap.empty())
        {
            auto [cost, node, rem, mask] = maxHeap.top(); maxHeap.pop();
            if(rem == 0)
            {
                res = max(res, cost);
            }
            if(dp[rem][node] > cost || rem == 0) continue;
            for(auto& [nei, c] : graph[node])
            {
                int newCost = c + cost; 
                if(((mask >> nei) & 1) && newCost > dp[rem - 1][nei])
                {
                    dp[rem - 1][nei] = newCost;
                    maxHeap.push({newCost, nei, rem - 1, mask ^ (1 << nei)});
                }
            }
        }
        return res;
    }
    int maximumCost(int n, vector<vector<int>>& highways, int k) {
        this->n = n;
        graph.resize(n);
        int res = -1;
        for(auto& edge : highways)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
            res = max(res, edge[2]);
        }
        if(k == 1) return res;
        res = -1;
        for(int i = 0; i < n; i++)
        {
            res = max(res, dfs(i, k));
        }
        return res;
    }
};