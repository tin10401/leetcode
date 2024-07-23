class Solution {
public:
    vector<bitset<1001>> parent;
    vector<int> sum, nums;
    int dfs(int node, int par)
    {
        int total = nums[node];
        for(auto& nei : graph[node])
        {
            if(nei != par)
            {
                total ^= dfs(nei, node);
                parent[node] |= parent[nei];
            }
        }
        sum[node] = total;
        parent[node].set(node);
        return total;
    }
    vector<vector<int>> graph;
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
       this->nums = nums;
       int n = nums.size();
       parent.resize(n), graph.resize(n), sum.resize(n); 
       for(auto& edge : edges)
       {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
       }
       dfs(0, -1);
       int res = INT_MAX;
       for(int i = 1; i < n; i++)
       {
        for(int j = i + 1; j < n; j++)
        {
            if(parent[i][j])
            {
                vector<int> curr = {sum[0] ^ sum[i], sum[j], sum[i] ^ sum[j]};
                sort(begin(curr), end(curr));
                res = min(res, curr.back() - curr.front());
            }
            else if(parent[j][i])
            {
                vector<int> curr = {sum[0] ^ sum[j], sum[i], sum[j] ^ sum[i]};
                sort(begin(curr), end(curr));
                res = min(res, curr.back() - curr.front());
            }
            else
            {
                vector<int> curr = {sum[0] ^ sum[i] ^ sum[j], sum[i], sum[j]};
                sort(begin(curr), end(curr));
                res = min(res, curr.back() - curr.front());
            }
        }
       }
       return res;
    }
};