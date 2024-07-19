class UnionFind
{
    public:
    vector<int> root, rank;
    int n;
    UnionFind(int n)
    {
        this->n = n;
        root.resize(n, -1), rank.resize(n, 1);
    }

    int find(int x)
    {
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }

    void merge(int x, int y)
    {
        int u = find(x), v = find(y);
        if(u != v)
        {
            if(rank[v] > rank[u]) swap(u, v);
            rank[u] += rank[v];
            root[v] = u;
        }
    }

    int get(int i)
    {
        return rank[find(i)];
    }
};

class Solution {
public:
    vector<int> dp;
    vector<vector<int>> graph;
    int dfs(int node, int par)
    {
        int& res = dp[node];
        if(res != -1) return res;
        res = 1;
        for(auto& nei : graph[node])
        {
            if(nei != par) res += dfs(nei, node);
        }
        // res += (res > 0);
        return res;
    }
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        graph.resize(n), dp.resize(n, -1);
        vector<int> degree(n);
        for(int i = 0; i < n; i++)
        {
            graph[i].push_back(edges[i]);
            degree[edges[i]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto& nei : graph[node])
            {
                if(--degree[nei] == 0) q.push(nei);
            }
        }
        UnionFind root(n);
        for(int i = 0; i < n; i++)
        {
            if(degree[i]) root.merge(i, edges[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(degree[i]) dp[i] = root.get(i);
        }
        for(int i = 0; i < n; i++)
        {
            dfs(i, -1);
        }
        return dp;
    }
};