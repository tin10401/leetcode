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

    vector<vector<int>> compute()
    {
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++)
        {
            res[find(i)].push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, int> list;
        int n = 0;
        for(auto& e : equations)
        {
            auto x = e[0], y = e[1];
            if(!list.count(x)) list[x] = n++;
            if(!list.count(y)) list[y] = n++;
        }
        unordered_map<int, unordered_map<int, double>> answer;
        UnionFind root(n);
        for(int i = 0; i < values.size(); i++)
        {
            int u = list[equations[i][0]], v = list[equations[i][1]];
            double x = values[i];
            if(answer[u].count(v) && answer[u][v] != x) return true;
            root.merge(u, v);
            answer[u][v] = x;
            answer[v][u] = 1.0 / x;
        }
        auto eq = root.compute();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(!answer[i].count(j) || !answer[k].count(i) || !answer[k].count(j)) continue;
                    auto x = answer[i][j];
                    auto y = answer[k][i];
                    auto jk = answer[k][j];
                    if(abs(x * y - jk) >= 1e-5) return true;
                }
            }
        }
        return false;
    }
};