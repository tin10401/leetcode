class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        vector<vector<pair<int, int>>> graph(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        minHeap.push({fees[0], 0, 0});
        dp[0][0] = fees[0];
        while(!minHeap.empty())
        {
            auto [cost, node, time] = minHeap.top();
            minHeap.pop();
            if(node == n - 1) return cost;
            if(dp[node][time] < cost) continue;
            for(auto& [nei, c] : graph[node])
            {
                int newCost = cost + fees[nei];
                int newTime = c + time;
                if(newTime <= maxTime && dp[nei][newTime] > newCost)
                {
                    dp[nei][newTime] = newCost;
                    minHeap.push({newCost, nei, newTime});
                }
            }
        }
        return -1;
    }
};