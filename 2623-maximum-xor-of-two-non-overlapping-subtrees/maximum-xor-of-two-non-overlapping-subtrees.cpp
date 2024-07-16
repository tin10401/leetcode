using ll = long long;
class Trie
{
    public:
    Trie* children[2];
    Trie() : children{} {}

    void insert(ll num)
    {
        Trie* curr = this;
        for(int i = 47; i >= 0; i--)
        {
            int bits = (num >> i) & 1;
            if(!curr->children[bits]) curr->children[bits] = new Trie();
            curr = curr->children[bits];
        }   
    }

    ll search(ll num)
    {
        Trie* curr = this;
        ll res = 0;
        for(int i = 47; i >= 0; i--)
        {
            int bits = (num >> i) & 1;
            if(!curr) return 0;
            if(curr->children[!bits])
            {
                res |= (1LL << i);
                curr = curr->children[!bits];
            }
            else curr = curr->children[bits];
        }
        return res;
    }

};
class Solution {
public:
    vector<int> values;
    vector<ll> totalSum;
    ll res = 0;
    Trie* trie = new Trie();
    ll dfs1(int node, int par)
    {
        ll total = values[node];
        for(auto& nei : graph[node])
        {
            if(nei != par)
            {
                total += dfs1(nei, node);
            }
        }
        totalSum[node] = total;
        return total;
    }

    void dfs2(int node, int par)
    {
        res = max(res, trie->search(totalSum[node]));
        for(auto& nei : graph[node])
        {
            if(nei != par) dfs2(nei, node);
        }
        trie->insert(totalSum[node]);
    }
    
    vector<vector<int>> graph;
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        this->values = values;
        graph.resize(n), totalSum.resize(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back({edge[1]});
            graph[edge[1]].push_back({edge[0]});
        }     
        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};