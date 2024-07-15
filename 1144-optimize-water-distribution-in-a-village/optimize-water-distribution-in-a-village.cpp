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

    bool merge(int x, int y)
    {
        int u = find(x), v = find(y);
        if(u != v)
        {
            if(rank[v] > rank[v]) swap(u, v);
            rank[u] += rank[v];
            root[v] = u;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[2] < b[2];
        };
        int res = 0;
        UnionFind root(n + 2);
        for(int i = 0; i < wells.size(); i++)
        {
            pipes.push_back({i + 1, n + 1, wells[i]});
        }
        sort(begin(pipes), end(pipes), compare);
        for(auto& edge : pipes)
        {
            int u = edge[0], v = edge[1], cost = edge[2];
            if(root.merge(u, v)) 
            {
                res += cost;
            }
        }
        return res;
    }
};