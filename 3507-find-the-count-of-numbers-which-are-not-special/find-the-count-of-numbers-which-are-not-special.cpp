class Solution {
public:
    int nonSpecialCount(int l, int r) {
       int n = sqrt(r) + 1;
       vector<bool> primes(n + 1);
       primes[2] = true;
       for(int i = 3; i <= n; i += 2) primes[i] = true;
       for(int i = 3; i * i <= n; i += 2)
       {
        if(primes[i])
        {
            for(int j = i; j * i <= n; j += 2) primes[i * j] = false;
        }
       } 
       int res = 0;
       for(int i = 2; i <= n; i++)
       {
        if(primes[i])
        {
            if(i * i >= l && i * i <= r) res++;
        }
       }
       return r - l + 1 - res;
    }
};