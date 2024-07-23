class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        auto dfs = [&](int node, int par, int cand, auto& dfs) -> int
        {
            int total = nums[node];
            for(auto& nei : graph[node])
            {
                if(nei != par)
                {
                    total += dfs(nei, node, cand, dfs);
                }
            } 
            return total == cand ? 0 : total;
        };
        int sum = accumulate(begin(nums), end(nums), 0);
        for(int i = 1; i < sum; i++)
        {
            if(sum % i == 0) 
            {
                int ans = dfs(0, -1, i, dfs);
                if(ans == 0) return sum / i - 1;
            }
        }
        return 0;
    }
};