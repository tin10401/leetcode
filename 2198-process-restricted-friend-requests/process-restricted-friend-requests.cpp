class UnionFind
{
    public:
    vector<bitset<1000>> ban;
    int n;
    vector<bitset<1000>> children;
    vector<int> root, rank;
    UnionFind(int n, vector<vector<int>>& restrictions)
    {
        this->n = n;
        root.resize(n, -1), rank.resize(n, 1), ban.resize(n), children.resize(n);
        for(auto& it : restrictions)
        {
            int u = it[0], v = it[1];
            ban[u].set(v);
            ban[v].set(u);
        }
        for(int i = 0; i < n; i++)
        {
            children[i].set(i);
        }
    }


    int find(int x)
    {
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }

    bool merge(int x, int y)
    {
        int u = find(x), v = find(y);
        if(u == v) return true;
        if((children[u] & ban[v]).any() || (children[v] & ban[u]).any()) return false;
        if(rank[v] > rank[u]) swap(u, v);
        rank[u] += rank[v];
        children[u] |= children[v];
        ban[u] |= ban[v];
        root[v] = u;
        return true;
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind root(n, restrictions);
        vector<bool> res;
        for(auto& r : requests)
        {
            res.push_back(root.merge(r[0], r[1]));
        }
        return res;
    }
};