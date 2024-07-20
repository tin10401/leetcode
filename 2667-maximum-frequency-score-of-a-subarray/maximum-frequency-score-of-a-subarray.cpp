class Solution {
public:
    using ll = long long;
    ll mod = 1e9 + 7;
    ll compute(ll base, ll exp)
    {
        ll res = 1;
        while(exp)
        {
            if(exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
    int maxFrequencyScore(vector<int>& nums, int k) {
        if(k == 1) return *max_element(begin(nums), end(nums));
       ll res = 0;
       unordered_map<int, int> mp;
       ll total = 0;
       for(int i = 0; i < nums.size(); i++)
       {
            if(mp[nums[i]]) total = (total + mod - compute(nums[i], mp[nums[i]])) % mod;
            total = (total + compute(nums[i], ++mp[nums[i]])) % mod;
            if(i >= k - 1)
            {
                if(i >= k)
                {
                    total = (total - compute(nums[i - k], mp[nums[i - k]])) % mod;
                    if(--mp[nums[i - k]]) total = (total + mod + compute(nums[i - k], mp[nums[i - k]])) % mod;
                }
                res = max(res, total);
            }
       } 
       return res;
    }
};