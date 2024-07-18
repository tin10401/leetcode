class Solution {
public:
    int dp[100001];
    string s;
    vector<vector<int>> graph;
    int ans = 1;
    int dfs(int node, int par)
    {
        int& res = dp[node];
        if(res != -1) return res;
        vector<int> list;
        for(auto& nei : graph[node])
        {
            if(nei != par && s[nei] != s[node])
            {
                list.push_back(dfs(nei, node));
            }
        }
        sort(rbegin(list), rend(list));
        if(list.size() >= 2)
        {
            ans = max(ans, list.front() + list[1] + 1);
            return res = 1 + list.front();
        }
        if(!list.empty()) ans = max(ans, list.front() + 1);
        return res = (!list.empty() ? list.front() : 0) + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        memset(dp, -1, sizeof(dp));
        this->s = s;
        int n = parent.size();
        graph.resize(n);
        for(int i = 0; i < n; i++)
        {
            if(parent[i] != -1) graph[parent[i]].push_back(i);
        }
        for(int i = 0; i < n; i++)
        {
            dfs(i, -1);
        }
        return ans;
    }
};