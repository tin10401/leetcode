class UnionFind
{
    public:
    int n;
    vector<int> root, rank;
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

    bool merge(int x, int y)
    {
        int u = find(x), v = find(y);
        if(u == v) return false;
        root[v] = u;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans1, ans2;
        unordered_map<int, int> parent;
        for(auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            if(parent.count(v))
            {
                ans1 = {parent[v], v};
                ans2 = edge;
            }
            parent[v] = u;
        }
        UnionFind root(n + 1);
        for(auto& edge : edges)
        {
            if(edge == ans2) continue;
            int u = edge[0], v = edge[1];
            if(!root.merge(u, v))
            {
                return ans1.empty() ? edge : ans1;
            }
        }
        return ans2;
    }
};