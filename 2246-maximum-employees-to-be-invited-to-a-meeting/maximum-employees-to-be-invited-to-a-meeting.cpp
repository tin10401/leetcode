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
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> count(n, 1), degree(n);
        for(int i = 0; i < n; i++)
        {
            degree[favorite[i]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            int v = favorite[node];
            count[v] = max(count[v], count[node] + 1);
            if(--degree[v] == 0) q.push(v);
        }
        UnionFind root(n);
        for(int i = 0; i < n; i++)
        {
            if(degree[i]) root.merge(i, favorite[i]);
        }
        int res = 0, total = 0;
        for(int i = 0; i < n; i++)
        {
            if(!degree[i]) continue;
            int len = root.get(i);
            if(len == 2)
            {
                degree[favorite[i]]--;
                total += count[i] + count[favorite[i]];
            }
            else
            {
                res = max(res, len);
            }
        }
        return max(res, total);
    }
};