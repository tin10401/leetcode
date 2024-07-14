class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        ll res = 0, curr = 0, sum = accumulate(begin(nums), end(nums), 0LL);
        unordered_map<ll, ll> left, right;
        for(int i = 0; i < n - 1; i++)
        {
            curr += nums[i];
            right[sum - 2 * curr]++;
        }
        res = right[0], curr = 0;
        for(int i = 0; i < n; i++)
        {
            int diff = nums[i] - k;
            res = max(res, left[diff] + right[-diff]);
            curr += nums[i];
            left[sum - 2 * curr]++, right[sum - 2 * curr]--;
        }
        return res;
    }
};