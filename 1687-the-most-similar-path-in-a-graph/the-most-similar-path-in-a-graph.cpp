class Solution {
public:
    unordered_map<int, string> map; 
    vector<vector<int>> graph;
    vector<string> target;
    int dp[101][101], chose[101][101];
    int dfs(int index, int node)
    {
        if(index == target.size()) return 0;
        int &res = dp[index][node];
        if(res != -1) return res;
        res = INT_MAX;
        for(auto& nei : graph[node])
        {
            int next = (map[node] != target[index]) + dfs(index + 1, nei);
            if(next < res)
            {
                res = next;
                chose[index][node] = nei;
            }
        }
        return res;
    }
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        memset(dp, -1, sizeof(dp));
        this->target = targetPath;
        for(int i = 0; i < names.size(); i++)
        {
            map[i] = names[i];
        }
        graph.resize(n);
        for(auto& edge : roads)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int startNode = -1, shortestPath = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int ans = dfs(0, i);
            if(ans < shortestPath)
            {
                shortestPath = ans;
                startNode = i;
            }
        }
        vector<int> res;
        for(int i = 0; i < target.size(); i++)
        {
            res.push_back(startNode);
            startNode = chose[i][startNode];
        }
        return res;
    }
};