class Solution {
public:
    using ll = long long;
    const long long INF = 1e15;
    vector<ll> dfs(int src, vector<vector<pair<int, int>>>& graph)
    {
        int n = graph.size();
        vector<ll> res(n, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minHeap;
        minHeap.push({0, src});
        res[src] = 0;
        while(!minHeap.empty())
        {
            auto [cost, node] = minHeap.top(); minHeap.pop();
            if(res[node] < cost) continue;
            for(auto& [nei, c] : graph[node])
            {
                ll newCost = cost + c;
                if(newCost < res[nei])
                {
                    res[nei] = newCost;
                    minHeap.push({newCost, nei});
                }
            }
        }
        return res;
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n), revGraph(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            revGraph[edge[1]].push_back({edge[0], edge[2]});
        }    
        auto d1 = dfs(src1, graph), d2 = dfs(src2, graph), d3 = dfs(dest, revGraph);
        ll res = INF;
        for(int i = 0; i < n; i++)
        {
            res = min(res, d1[i] + d2[i] + d3[i]);
        }
        return res == INF ? -1 : res;
    }
};