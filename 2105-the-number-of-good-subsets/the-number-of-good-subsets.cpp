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
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> total(31), masks(31, -1);
        for(int i = 2; i < 31; i++)
        {   
            int mask = 0, num = i, count = 0; 
            for(int j = 0; j < primes.size(); j++)
            {
                int p = primes[j];
                if(num % p == 0)
                {
                    if((num / p) % p == 0) 
                    {
                        mask = -1;
                        break;
                    }
                    mask |= (1 << j);
                    count++;
                }
            }
            if(mask != -1) masks[i] = mask;
        }
        int ones = 0;
        for(auto& num : nums)
        {
            if(num == 1) ones++;
            else if(masks[num] != -1) total[num]++;
        }
        int n = primes.size();
        ll dp[1 << n] ;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 2; i < 31; i++)
        {
            if(total[i])
            {
                int curr = masks[i];
                for(int j = (1 << n) - 1; j >= 0; j--)
                {
                    if((j & curr) == 0)
                    {
                        dp[j | curr] = (dp[j | curr] + dp[j] * total[i]) % mod;
                    }
                }
            }
        }
        int res = 0;
        for(int i = 1; i < 1 << n; i++)
        {
            res = (res + dp[i]) % mod;
        }
        if(ones) return ((ll)res * compute(2, ones)) % mod; 
        return res;
    }   
};