#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string s) {
        using ll = long long;
        ll mod1 = 1e9 + 7, mod2 = 1e9 + 33;
        int n = s.size();
        vector<ll> hash1(n + 1, 0), hash2(n + 1, 0);
        vector<ll> pow1(n + 1, 1), pow2(n + 1, 1);
        
        for (int i = 1; i <= n; ++i) {
            hash1[i] = (hash1[i - 1] * 26 + (s[i - 1] - 'a' + 1)) % mod1;
            hash2[i] = (hash2[i - 1] * 26 + (s[i - 1] - 'a' + 1)) % mod2;
            pow1[i] = (pow1[i - 1] * 26) % mod1;
            pow2[i] = (pow2[i - 1] * 26) % mod2;
        }

        set<pair<ll, ll>> vis;
        for (int len = 1; len * 2 <= n; ++len) {
            for (int i = 0; i + 2 * len <= n; ++i) {
                ll leftHash1 = (hash1[i + len] - hash1[i] * pow1[len] % mod1 + mod1) % mod1;
                ll leftHash2 = (hash2[i + len] - hash2[i] * pow2[len] % mod2 + mod2) % mod2;
                ll rightHash1 = (hash1[i + 2 * len] - hash1[i + len] * pow1[len] % mod1 + mod1) % mod1;
                ll rightHash2 = (hash2[i + 2 * len] - hash2[i + len] * pow2[len] % mod2 + mod2) % mod2;
                if (leftHash1 == rightHash1 && leftHash2 == rightHash2) {
                    vis.insert({leftHash1, leftHash2});
                }
            }
        }
        return vis.size();
    }
};
