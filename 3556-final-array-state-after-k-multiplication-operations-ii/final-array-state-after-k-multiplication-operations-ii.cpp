class Solution {
public:
#define ll long long
#define ff first
#define ss second
#define pll pair<ll, ll>
    ll modExpo(ll base, ll exp, ll mod)
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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums;
        set<pll> s;
        int MOD = 1e9 + 7, n = nums.size(), mx = *max_element(begin(nums), end(nums));
        for(int i = 0; i < n; i++) s.insert({(ll)nums[i], (ll)i});
        while(s.begin()->ff * multiplier <= s.rbegin()->ff && k) // bring the number in the set as close as possible together
        {
            k--;
            pll tmp = *s.begin();
            s.erase(tmp);
            s.insert({(tmp.ff * multiplier), tmp.ss});
        }
        int take = modExpo(multiplier, k / n, MOD);
        k %= n; // leftOver
        for(auto& [a, f] : s)
        {
            ll b = (a * take % MOD * (k-- > 0 ? multiplier : 1)) % MOD;
            nums[f] = b;
        }
        return nums;

    }
};