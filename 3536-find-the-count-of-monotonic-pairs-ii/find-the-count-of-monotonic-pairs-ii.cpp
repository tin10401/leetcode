class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        using ll = long long;
        int MOD = 1e9 + 7, n = nums.size();
        vector<ll> prefix(1002, 0);
        vector<ll> dp(1001, 0);   
        fill(dp.begin(), dp.begin() + nums.front() + 1, 1);
        iota(prefix.begin(), prefix.end(), 0);

        for (int i = 1; i < n; ++i) {
            vector<ll> next_prefix(1002, 0);
            vector<ll> next_dp(1001, 0);   

            for (ll j = 0; j <= nums[i]; ++j) {
                int id = min(j, max(-1ll, nums[i - 1] - nums[i] + j)) + 1;
                next_dp[j] = prefix[id] % MOD;
                next_prefix[j + 1] = (next_prefix[j] + next_dp[j]) % MOD;
            }
            swap(dp, next_dp);
            swap(prefix, next_prefix);
        }

        int res = 0;
        for (int j = 0; j <= nums.back(); ++j) {
            res = (res + dp[j]) % MOD;
        }

        return res;
    }
};