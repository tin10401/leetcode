class Solution {
public:
    vector<pair<int, int>> list;
    vector<vector<int>> graph;
    vector<int> nums, res, bestDepth;
    void dfs(int node, int par, int curr)
    {
        for(int i = 0; i < 51; i++)
        {
            auto [depth, index] = list[i];
            if(depth > bestDepth[node] && gcd(i, nums[node]) == 1)
            {
                bestDepth[node] = depth;
                res[node] = index;
            }
        }
        auto prev = list[nums[node]];
        list[nums[node]] = {curr, node};
        for(auto& nei : graph[node])
        {
            if(nei != par) dfs(nei, node, curr + 1);
        }
        list[nums[node]] = prev;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(); 
        this->nums = nums;
        graph.resize(n), res.resize(n, -1), bestDepth.resize(n, -1);
        list.resize(51, {-1, -1});
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, 0);
        return res;
    }
};