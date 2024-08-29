class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans, jump(--n); 
        iota(jump.begin(), jump.end(), 1); 
        for (auto& q : queries) {
            int u = q[0], v = q[1]; 
            for (; jump[u] < v; --n) 
                tie(jump[u], u, u) = make_tuple(v, jump[u], jump[u]);
            ans.push_back(n); 
        }
        return ans; 
    }
};