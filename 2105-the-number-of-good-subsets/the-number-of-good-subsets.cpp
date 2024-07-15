
class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;
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
        int masks[31];
        memset(masks, -1, sizeof(masks));
        for(int i = 2; i < 31; i++)
        {   
            int mask = 0, num = i; 
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
                }
            }
            if(mask != -1) masks[i] = mask;
        }
        
        vector<int> total(31);
        int ones = 0;
        for(int num : nums)
        {
            if(num == 1) ones++;
            else total[num]++;
        }

        vector<long> dp(1 << primes.size(), 0);
        dp[0] = 1; // Empty subset

        for(int i = 2; i <= 30; i++)
        {
            if(total[i] > 0 && masks[i] != -1)
            {
                int currMask = masks[i];
                for(int j = (1 << primes.size()) - 1; j >= 0; j--)
                {
                    if((j & currMask) == 0)
                    {
                        dp[j | currMask] = (dp[j | currMask] + dp[j] * total[i]) % mod;
                    }
                }
            }
        }

        long res = 0;
        for(int i = 1; i < (1 << primes.size()); i++)
        {
            res = (res + dp[i]) % mod;
        }

        // Include subsets containing 1
        if (ones > 0) {
            res = (res * compute(2, ones)) % mod;
        }

        return (int)res;
    }
};
