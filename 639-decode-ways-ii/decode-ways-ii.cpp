class Solution {
public:
    using ll = long long;
    int numDecodings(string s) {
        ll curr = 1;
        ll next = 0;
        int mod = 1e9 + 7;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0') next = curr, curr = 0;
            else
            {
                ll temp = next;
                next = curr;
                curr = (curr * (s[i] == '*' ? 9 : 1)) % mod;
                if(i < n - 1)
                {
                    if(s[i] == '*' && s[i + 1] == '*')
                    {
                        curr += temp * 15;
                        curr %= mod;
                    }
                    else if(s[i] == '*')
                    {
                        curr += temp * (s[i + 1] <= '6' ? 2 : 1);
                        curr %= mod;
                    }
                    else if(s[i + 1] == '*')
                    {
                        curr += temp * (s[i] == '1' ? 9 : (s[i] == '2' ? 6 : 0));
                        curr %= mod;
                    }
                    else if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                    {
                        curr += temp;
                        curr %= mod;
                    }
                }
            }
        }
        return curr;
    }
};