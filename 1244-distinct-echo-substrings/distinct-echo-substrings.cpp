class Solution {
public:
    int distinctEchoSubstrings(string s) {
        using ll = long long;
        ll mod1 = 1e9 + 7, mod2 = 1e9 + 33, pow1 = 1, pow2 = 1, n = s.size(), hash1 = 0, hash2 = 0;
        vector<pair<ll, ll>> prefix(n + 1, {0, 0}), power(n + 1, {1, 1});
        for(int i = 1; i <= n; i++)
        {
            hash1 = (hash1 * 26 + s[i - 1] - '0') % mod1;
            hash2 = (hash2 * 26 + s[i - 1] - '0') % mod2;
            pow1 = (pow1 * 26) % mod1;
            pow2 = (pow2 * 26) % mod2;
            prefix[i] = {hash1, hash2};
            power[i] = {pow1, pow2};
        }
        set<pair<ll, ll>> vis;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; i - j >= 0 && i + j + 1 < n; j++)
            {
                ll leftHash1 = (prefix[i + 1].first - (prefix[i - j].first * power[j + 1].first % mod1) + mod1) % mod1;
                ll leftHash2 = (prefix[i + 1].second - (prefix[i - j].second * power[j + 1].second % mod2) + mod2) % mod2;
                ll rightHash1 = (prefix[i + j + 2].first - (prefix[i + 1].first * power[j + 1].first % mod1) + mod1) % mod1;
                ll rightHash2 = (prefix[i + j + 2].second - (prefix[i + 1].second * power[j + 1].second % mod2) + mod2) % mod2;
                if(leftHash1 == rightHash1 && leftHash2 == rightHash2) vis.insert({leftHash1, leftHash2});
            }
        }
        return vis.size();
    }
    
};