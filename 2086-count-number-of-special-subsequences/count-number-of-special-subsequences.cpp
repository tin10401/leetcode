class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        using ll = long long;
        ll zero = 0, one = 0, two = 0, mod = 1e9 + 7;
        for(auto& num : nums)
        {
            if(num == 0) zero = (zero * 2 + 1) % mod;
            else if(num == 1) one = (zero + 2 * one) % mod;
            else two = (one + 2 * two) % mod;
        }
        return two;
    }
};