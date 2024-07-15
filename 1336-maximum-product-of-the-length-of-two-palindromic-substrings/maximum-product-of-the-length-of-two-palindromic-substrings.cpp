class Solution {
public:
    long long maxProduct(string s) {
        using ll = long long;
        ll res = 0, l = 0, n = s.size();
        vector<int> m(n), r(n);
        for(int i = 0, l = 0, r = -1; i < n; i++)
        {
            int k = i > r ? 1 : min(m[l + r - i], r - i + 1);
            while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            m[i] = k--;
            if(i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }
        vector<ll> prefix(n), suffix(n);
        for(int i = 0; i < n; i++)
        {
            int d = m[i];
            prefix[i + d - 1] = fmax(prefix[i + d - 1], d + d - 1);
        }
        for(int i = n - 2; i >= 0; i--)
        {
            prefix[i] = max(prefix[i], prefix[i + 1] - 2);
        }
        for(int i = 1; i < n; i++) prefix[i] = max(prefix[i], prefix[i - 1]);
        for(int i = n - 1; i >= 0; i--)
        {
            int d = m[i];
            suffix[i - d + 1] = fmax(suffix[i - d + 1], d + d - 1);
        }
        for(int i = 1; i < n; i++)
        {
            suffix[i] = max(suffix[i], suffix[i - 1] - 2);
        }
        for(int i = n - 2; i >= 0; i--) suffix[i] = max(suffix[i], suffix[i + 1]);
        for(int i = 0; i < n - 1; i++)
        {
            res = max(res, prefix[i] * suffix[i + 1] * 1LL);
        }

        return res;
    }
};