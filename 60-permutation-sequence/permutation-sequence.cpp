class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);
        for(int i = 2; i <= n; i++)
        {
            factorial[i] = factorial[i - 1] * i;
        }
        string res;
        vector<int> s(n);
        k--;
        iota(begin(s), end(s), 1);
        for(int i = 0; i < n; i++)
        {
            int part = factorial[n - i - 1];
            int num = k / part;
            res += to_string(s[num]);
            s.erase(s.begin() + num);
            k %= part;
        }
        return res;
    }
};