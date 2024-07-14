class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2] + 1});
            graph[edge[1]].push_back({edge[0], edge[2] + 1});
        }
        vector<int> dis(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});
        dis[0] = 0;
        while(!minHeap.empty())
        {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            if(dis[node] != cost) continue;
            for(auto& [nei, c] : graph[node])
            {
                int newCost = c + cost;
                if(newCost < dis[nei])
                {
                    dis[nei] = newCost;
                    minHeap.push({newCost, nei});
                }
            }
        }
        int res = 0;
        for(auto& d : dis)
        {
            if(d <= maxMoves) res++;
        }
        for(auto& edge : edges)
        {
            int u = edge[0], v = edge[1], d = edge[2];
            int left = max(0, maxMoves - dis[u]);
            int right = max(0, maxMoves - dis[v]);
            res += min(d, left + right);
        }
        return res;
    }
};