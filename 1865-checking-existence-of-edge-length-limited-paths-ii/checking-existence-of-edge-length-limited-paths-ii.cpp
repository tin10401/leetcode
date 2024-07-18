class DistanceLimitedPathsExist {
public:
    vector<vector<pair<int, int>>> graph;
    vector<int> vis;
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
        graph.resize(n), vis.resize(n);
        for(auto& edge : edgeList)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
    }
    
    bool query(int p, int q, int limit) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, p});
        fill(begin(vis), end(vis), 0);
        while(!minHeap.empty())
        {
            auto [cost, node] = minHeap.top(); minHeap.pop();
            if(node == q) return true;
            if(vis[node]) continue;
            vis[node] = true;
            for(auto& [nei, c] : graph[node])
            {
                if(c >= limit || vis[nei]) continue;
                minHeap.push({cost + c, nei}); 
            }
        }
        return false;
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */