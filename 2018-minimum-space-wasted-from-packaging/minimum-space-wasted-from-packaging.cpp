class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        using ll = long long;
        ll res = LLONG_MAX, mod = 1e9 + 7;
        sort(begin(packages), end(packages));
        int n = packages.size();
        vector<ll> prefix(n + 1);
        for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + packages[i - 1];
        auto compute = [&](vector<int>& box) {
            if(packages.back() > box.back()) return LLONG_MAX;
            ll prev = 0, total = 0;
            for(auto& b : box) {
                auto it = upper_bound(begin(packages) + prev, end(packages), b);
                ll next = distance(begin(packages), it);
                total += (ll)b * (next - prev) - (prefix[next] - prefix[prev]);
                prev = next;
            }
            return total;
        };
        
        for(auto& box : boxes) {
            sort(begin(box), end(box));
            res = min(res, compute(box));
        }
        
        return res == LLONG_MAX ? -1 : res % mod;
    }
};