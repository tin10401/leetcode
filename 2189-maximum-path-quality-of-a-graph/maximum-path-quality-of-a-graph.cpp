class Solution {
public:
    int res = 0;
    vector<vector<pair<int, int>>> graph;
    vector<int> values, s;
    int maxTime;
    void dfs(int node, int time, int curr)
    {
        if(node == 0)
        {
            res = max(res, curr);
        }
        for(auto& [nei, t] : graph[node])
        {
            int next = time + t;
            if(next <= maxTime)
            {
                int ori = values[nei];
                values[nei] = 0;
                dfs(nei, next, curr + ori);
                values[nei] = ori;
            }
        }
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        this->maxTime = maxTime;
        this->values = values;
        graph.resize(values.size());
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        res = values[0];
        dfs(0, 0, 0);
        return res;
    }
};