class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
        vector<vector<pair<int, int>>> graph(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        minHeap.push({0, s, k});
        dp[s][k] = 0;
        while(!minHeap.empty())
        {
            auto [cost, node, rem] = minHeap.top();
            minHeap.pop();
            if(node == d) return cost;
            if(dp[node][rem] < cost) continue;
            for(auto& [nei, c] : graph[node])
            {
                int newCost = cost + c;
                if(newCost < dp[nei][rem])
                {
                    dp[nei][rem] = newCost;
                    minHeap.push({newCost, nei, rem});
                }
                if(rem && cost < dp[nei][rem - 1])
                {
                    dp[nei][rem - 1] = cost;
                    minHeap.push({cost, nei, rem - 1});
                }
            }
        }
        return -1;
    }
};