class Solution {
public:
    int sz;
    map<vector<int>, int> dp;
    int dfs(vector<int>& cnt, int rem)
    {
        if(dp.count(cnt)) return dp[cnt];
        int& res = dp[cnt];
        for(int i = 1; i < sz; i++)
        {
            if(--cnt[i] >= 0)
            {
                int newRem = (rem + i) % sz;
                res = max(res, (rem == 0) + dfs(cnt, newRem));
            }
            ++cnt[i];
        }
        return res;
    }
    int maxHappyGroups(int sz, vector<int>& groups) {
        this->sz = sz;
        vector<int> cnt(sz);
        int res = 0;
        for(auto& g : groups)
        {
            if(g % sz == 0) res++;
            else if(cnt[(sz - g % sz) % sz])
            {
                res++;
                --cnt[(sz - g % sz) % sz];
            }
            else ++cnt[g % sz];
        }
        return res + dfs(cnt, 0);
    }
};