class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        using ll = long long;
        int mmax = *max_element(begin(nums), end(nums));
        ll counter[mmax + 1], prefix[mmax + 1], res = 0, mod = 1e9 + 7;
        memset(counter, 0, sizeof(counter)), memset(prefix, 0, sizeof(prefix));
        for(auto& num : nums) counter[num]++;
        for(int i = 1; i <= mmax; i++) prefix[i] = prefix[i - 1] + counter[i];
        for(int i = 1; i <= mmax; i++)
        {
            if(counter[i] == 0) continue;
            for(int j = i; j <= mmax; j += i)
            {
                int left = j, right = min(mmax, j + i - 1);
                res = (res + counter[i] * (prefix[right] - prefix[left - 1]) * (j / i)) % mod;
            }
        }
        return res;
    }
};