class Solution {
public:
    void dfs(int node)
    {
        if(vis[node]) return;
        vis[node] = true;
        for(auto& child : graph[node]) dfs(child);
        mark[nums[node]] = true;
    }
    vector<vector<int>> graph;
    vector<int> vis, mark, nums;
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        graph.resize(n), vis.resize(n), mark.resize((int)1e5 + 2);
        this->nums = nums;
        vector<int> res(n, 1);
        for(int i = 1; i < n; i++) graph[parents[i]].push_back(i);
        auto it = find(begin(nums), end(nums), 1);
        if(it == nums.end()) return res;
        int node = it - begin(nums);
        int curr = 2;
        while(node != -1)
        {
            dfs(node);
            while(mark[curr]) curr++;
            res[node] = curr;
            node = parents[node];
        }
        return res;
    }
};