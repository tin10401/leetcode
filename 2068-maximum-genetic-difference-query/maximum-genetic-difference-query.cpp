#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Trie {
public:
    Trie* children[2];
    int count;

    Trie() : children{nullptr, nullptr}, count(0) {}

    void insert(int num) {
        Trie* curr = this;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new Trie();
            }
            curr = curr->children[bit];
            curr->count++;
        }
    }

    void erase(int num) {
        Trie* curr = this;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            curr = curr->children[bit];
            curr->count--;
        }
    }

    int search(int num) {
        Trie* curr = this;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->children[!bit] && curr->children[!bit]->count > 0) {
                res |= (1 << i);
                curr = curr->children[!bit];
            } else {
                curr = curr->children[bit];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<pair<int, int>>> nodeQueries;
    vector<int> res;
    Trie trie;

    void dfs(int node) {
        trie.insert(node);
        for (const auto& [queryIndex, val] : nodeQueries[node]) {
            res[queryIndex] = trie.search(val);
        }
        for (int child : graph[node]) {
            dfs(child);
        }
        trie.erase(node);
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        graph.resize(n);
        nodeQueries.resize(n);
        res.resize(queries.size());

        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (parents[i] == -1) {
                root = i;
            } else {
                graph[parents[i]].push_back(i);
            }
        }

        for (int i = 0; i < queries.size(); ++i) {
            int node = queries[i][0];
            int val = queries[i][1];
            nodeQueries[node].emplace_back(i, val);
        }

        dfs(root);

        return res;
    }
};
