class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> tree(n);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        auto fn = [&](int u, int p, int cand, auto& fn) -> int {
            int ans = nums[u];
            for(int v : tree[u]) {
                if (v != p) {
                    ans += fn(v, u, cand, fn);
                }
            }
            return (ans == cand) ? 0 : ans;
        };

        int total = accumulate(nums.begin(), nums.end(), 0);
        for(int cand = 1; cand <= total / 2; ++cand) {
            if (total % cand == 0) {
                int result = fn(0, -1, cand, fn);
                if (result == 0) {
                    return total / cand - 1;
                }
            }
        }
        return 0;
    }
};