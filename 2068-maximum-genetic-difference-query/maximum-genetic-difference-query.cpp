class Trie
{
    public:
    Trie* children[2];
    int count;
    Trie() : count(0), children{} {}

    void update(int num, int val)
    {
        Trie* curr = this;
        for(int i = 31; i >= 0; i--)
        {
            int bits = (num >> i) & 1;
            if(!curr->children[bits]) curr->children[bits] = new Trie();
            curr = curr->children[bits];
            curr->count += val;
        }
    }

    int search(int num)
    {
        Trie* curr = this;
        int res = 0;
        for(int i = 31; i >= 0; i--)
        {
            int bits = (num >> i) & 1;
            if(curr->children[!bits] && curr->children[!bits]->count)
            {
                curr = curr->children[!bits];
                res |= (1 << i);
            }
            else curr = curr->children[bits];
        }
        return res;
    }
};
class Solution {
public:
    void dfs(int node)
    {
        trie->update(node, 1);
        for(auto& [val, index] : nodes[node])
        {
            res[index] = trie->search(val);
        }
        for(auto& nei : graph[node])
        {
            dfs(nei);
        }
        trie->update(node, -1);
    }
    vector<vector<int>> graph;
    vector<vector<pair<int, int>>> nodes;
    vector<int> res;
    Trie* trie = new Trie();
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int startNode = -1, n = parents.size();
        graph.resize(n), res.resize(queries.size()), nodes.resize(n);
        for(int i = 0; i < n; i++)
        {
            if(parents[i] == -1) startNode = i;
            else graph[parents[i]].push_back(i);
        }
        for(int i = 0; i < queries.size(); i++)
        {
            int node = queries[i][0], val = queries[i][1];
            nodes[node].push_back({val, i});
        }
        dfs(startNode);
        return res;
    }
};