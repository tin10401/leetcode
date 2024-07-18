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
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto& nei : graph[node])
        {
            if(nei != par && s[nei] != s[node])
            {
                minHeap.push(dfs(nei, node));
                if(minHeap.size() > 2) minHeap.pop();
            }
        }
        int total = 1, next = 0;
        while(!minHeap.empty())
        {
            total += minHeap.top(); next = minHeap.top(); minHeap.pop();
        }
        ans = max(ans, total);
        return res = next + 1;
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