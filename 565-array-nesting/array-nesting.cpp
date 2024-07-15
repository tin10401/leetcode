class Solution {
public:
    unordered_set<int> vis;
    int dfs(int node)
    {
        if(vis.count(node)) return 0;
        vis.insert(node);
        return 1 + dfs(nums[node]);
    }
    vector<int> nums;
    int arrayNesting(vector<int>& nums) {
        this->nums = nums;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res = max(res, dfs(i));
        }
        return res;
    }
};