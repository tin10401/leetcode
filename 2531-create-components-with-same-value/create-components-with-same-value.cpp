class Solution {
public:
    bool dfs2(int node, int par, int per, int left)
    {
        if(left == 0) left = per;
        if(nums[node] > left) return false;
        int total = 0;
        for(auto& nei : graph[node])
        {
            if(nei != par)
            {
                int nLeft = sum[nei] % per;
                total += nLeft;
                if(!dfs2(nei, node, per, nLeft)) return false;
            }
        }
        return (total + nums[node]) == left;
    }
    int dfs(int node, int par)
    {
        int total = nums[node];
        for(auto& nei : graph[node])
        {
            if(nei != par) total += dfs(nei, node);
        }
        sum[node] = total;
        return total;
    }
    vector<int> nums, sum;
    vector<vector<int>> graph;
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        int n = nums.size();
        graph.resize(n), sum.resize(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1);
        int total = accumulate(begin(nums), end(nums), 0);
        vector<int> list;
        for(int i = 1; i <= total; i++)
        {
            if(total % i == 0)
            {
                if(dfs2(0, -1, i, 0)) return (total / i) - 1; 
            }
        }     
        return 0;
    }
};