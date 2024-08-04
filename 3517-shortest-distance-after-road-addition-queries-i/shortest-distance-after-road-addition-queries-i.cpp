class Solution {
public:
    int n;
    vector<vector<pair<int, int>>> graph;
    int dfs()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dp(n, 1e9);
        minHeap.push({0, 0});
        dp[0] = 0;
        while(!minHeap.empty())
        {
            auto [cost, node] = minHeap.top(); minHeap.pop();
            if(node == n - 1) return cost;
            if(dp[node] != cost) continue;
            for(auto& [nei, c] : graph[node])
            {
                int newCost = c + cost;
                if(newCost < dp[nei])
                {
                    dp[nei] = newCost;
                    minHeap.push({newCost, nei});
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        this->n = n;
        graph.resize(n);
        for(int i = 1; i < n; i++)
        {
            graph[i - 1].push_back({i, 1});
        }
        for(auto& q : queries)
        {
            graph[q[0]].push_back({q[1], 1});
            res.push_back(dfs());
        }
        return res;
    }
};