class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        unordered_map<int, int> mp;
        int res = INT_MIN, n = flowers.size();
        vector<int> prefix(n + 1);
        for(int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + max(0, flowers[i - 1]);
        }
        for(int i = 0; i < n; i++)
        {
            int f = flowers[i];
            if(!mp.count(f))
            {
                mp[f] = i;
            }
            else
            {
                res = max(res, prefix[i] - prefix[mp[f] + 1] + 2 * f);
            }
        }
        return res;

    }
};