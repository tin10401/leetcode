class UnionFind
{
    public:
    vector<int> root, rank, weight;
    int n;
    UnionFind()
    {
        this->n = 1e4 + 1;
        root.resize(n), rank.resize(n, 1), weight.resize(n);
        iota(begin(root), end(root), 0);
    }

    int find(int x, int limit)
    {
        if(root[x] == x || weight[x] >= limit) return x;
        return find(root[x], limit);
    }

    void merge(int x, int y, int limit)
    {
        int u = find(x, INT_MAX);
        int v = find(y, INT_MAX);
        if(u != v)
        {
            if(rank[v] > rank[u]) swap(u, v);
            rank[u] += rank[v];
            root[v] = u;
            weight[v] = limit;
        }
    }
};

class DistanceLimitedPathsExist {
public:
    UnionFind root;
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[2] < b[2];
        };
        sort(begin(edgeList), end(edgeList), compare);
        for(auto& edge : edgeList)
        {
            root.merge(edge[0], edge[1], edge[2]);
        }
    }
    
    bool query(int p, int q, int limit) {
        return root.find(p, limit) == root.find(q, limit);
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */