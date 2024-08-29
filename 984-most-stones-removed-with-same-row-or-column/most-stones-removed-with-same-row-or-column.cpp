class UnionFind
{
    public:
    int root[20001], rank[20001], vis[20001];
    int n = 20001;
    UnionFind()
    {
        fill(root, root + 20001, -1);
        fill(rank, rank + 20001, 1);
        fill(vis, vis + 20001, false);
    }

    int find(int x)
    {
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }

    void merge(int x, int y)
    {
        vis[x] = true;
        vis[y] = true;
        int u = find(x);
        int v = find(y);
        if(u != v)
        {
            if(rank[u] < rank[v]) swap(u, v);
            rank[u] += rank[v];
            root[v] = u;
        }
    }

    int get()
    {
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(find(i) == i && vis[i]) res++;
        }
        return res;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind root;
        for(auto& it : stones)
        {
            root.merge(it[0], it[1] + 10001);
        }
        return stones.size() - root.get();   
    }
};