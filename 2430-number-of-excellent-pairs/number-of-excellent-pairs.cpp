class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        using ll = long long;
        int bits[62] = {};
        unordered_set<int> s(begin(nums), end(nums));
        for(auto& num : s) bits[__builtin_popcount(num)]++;
        for(int i = 60; i >= 0; i--) bits[i] += bits[i + 1];
        ll res = 0;
        for(auto& num : s) res += bits[max(0, k - __builtin_popcount(num))];
        return res;
    }
};