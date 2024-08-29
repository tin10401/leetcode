class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> tree(5, vector<int>(32, -1));
        for(auto& num : nums)
        {
            int level = num / 100;
            int pos = (num / 10) % 10;
            int val = num % 10;
            tree[level - 1][pos - 1] = val;
        }
        dfs(0, 0, 0, tree);
        return res;
    }
    int res = 0;
    int dfs(int curr, int level, int pos, vector<vector<int>>& tree)
    {
        if(tree[level][pos] == -1) return 0;
        curr += tree[level][pos];
        int left = dfs(curr, level + 1, pos * 2 + 1, tree);
        int right = dfs(curr, level + 1, pos * 2, tree);
        if(left == 0 && right == 0) res += curr;
        return 1;
    }
};