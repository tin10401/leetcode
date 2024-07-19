class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<unordered_set<int>> tree(n);
        for(int i = 0; i < n; i++)
        {
            tree[i] = unordered_set<int>();
        }

        for(auto& e : edges)
        {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        vector<int> leaf;
        for(int i = 0; i < n; i++)
        {
            int u = i;
            while(tree[u].size() == 1 && coins[u] == 0)
            {
                int v = *tree[u].begin();
                tree[u].erase(v);
                tree[v].erase(u);
                u = v;
            }
            if(tree[u].size() == 1)
            {
                leaf.push_back(u);
            }
        }

        for(int sz = 2; sz; sz--)
        {
            vector<int> temp;
            for(auto& u : leaf)
            {
                if(tree[u].size() == 1)
                {
                    int v = *tree[u].begin();
                    tree[u].erase(v);
                    tree[v].erase(u);
                    if(tree[v].size() == 1) temp.push_back(v);
                }
            }
            leaf = temp;
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += tree[i].size();
        }
        return res;
    }
};