class Solution {
public:
    vector<int> vis;
    int dfs(int node)
    {
        if(vis[node]) return 0;
        vis[node] = true;
        return 1 + dfs(nums[node]);
    }
    vector<int> nums;
    int arrayNesting(vector<int>& nums) {
        this->nums = nums;
        vis.resize(nums.size());
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res = max(res, dfs(i));
        }
        return res;
    }
};