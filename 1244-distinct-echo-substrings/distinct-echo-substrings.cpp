#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string s) {
        using ll = long long;
        ll mod1 = 1e9 + 7, mod2 = 1e9 + 33;
        int n = s.size();
        vector<pair<ll, ll>> prefix(n + 1, {0, 0}), power(n + 1, {1, 1});

        // Compute prefix hashes and powers
        for(int i = 1; i <= n; i++) {
            prefix[i].first = (prefix[i - 1].first * 26 + (s[i - 1] - 'a' + 1)) % mod1;
            prefix[i].second = (prefix[i - 1].second * 26 + (s[i - 1] - 'a' + 1)) % mod2;
            power[i].first = (power[i - 1].first * 26) % mod1;
            power[i].second = (power[i - 1].second * 26) % mod2;
        }

        set<pair<ll, ll>> vis;
        for(int i = 0; i < n; i++) {
            for(int j = 0; i - j >= 0 && i + j + 1 < n; j++) {
                ll leftHash1 = (prefix[i + 1].first - (prefix[i - j].first * power[j + 1].first % mod1) + mod1) % mod1;
                ll leftHash2 = (prefix[i + 1].second - (prefix[i - j].second * power[j + 1].second % mod2) + mod2) % mod2;
                ll rightHash1 = (prefix[i + j + 2].first - (prefix[i + 1].first * power[j + 1].first % mod1) + mod1) % mod1;
                ll rightHash2 = (prefix[i + j + 2].second - (prefix[i + 1].second * power[j + 1].second % mod2) + mod2) % mod2;
                if(leftHash1 == rightHash1 && leftHash2 == rightHash2) {
                    vis.insert({leftHash1, leftHash2});
                }
            }
        }
        return vis.size();
    }
};
