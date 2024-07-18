class UnionFind
{
    public:
    vector<unordered_set<int>> ban;
    unordered_set<int> rootSet;
    int n;
    vector<unordered_set<int>> children;
    vector<int> root, rank;
    UnionFind(int n, vector<vector<int>>& restrictions)
    {
        this->n = n;
        root.resize(n, -1), rank.resize(n, 1), ban.resize(n), children.resize(n);
        for(auto& it : restrictions)
        {
            int u = it[0], v = it[1];
            ban[u].insert(v);
            ban[v].insert(u);
        }
        for(int i = 0; i < n; i++)
        {
            children[i].insert(i);
        }
    }


    int find(int x)
    {
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }

    bool search(unordered_set<int>& a, unordered_set<int>& b)
    {
        for(auto& n : a)
        {
            for(auto& all : ban[n])
            {
                if(b.count(all)) return false;
            }
        }
        return true;
    }

    bool merge(int x, int y)
    {
        int u = find(x), v = find(y);
        if(u == v) return true;
        if(!search(children[u], children[v])) return false;
        if(rank[v] > rank[u]) swap(u, v);
        rank[u] += rank[v];
        children[u].insert(children[v].begin(), children[v].end());
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