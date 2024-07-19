class Solution {
public:
    double res = 1.00;
    bool found = false;
    int dfs(int node, int par, double curr, int t, int target)
    {
        double next = 1.00 / (graph[node].size() - (par != -1)) * curr; 
        int count = 0;
        for(auto& nei : graph[node])
        {
            if(nei != par)
            {
                count += dfs(nei, node, next, t - 1, target);
            }
        }
        if(node == target && t >= 0)
        {
            if(t == 0 || count == 0) res *= curr, found = true;
        }
        return count + 1;
    }
    vector<vector<int>> graph;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        graph.resize(n + 1);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(1, -1, 1.00, t, target);
        return found ? res : 0;
    }
};