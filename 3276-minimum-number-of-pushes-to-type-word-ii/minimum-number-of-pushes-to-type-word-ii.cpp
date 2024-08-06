class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vis(26, 0);
        for(auto& ch : word)
        {
            vis[ch - 'a']++;
        }
        sort(vis.rbegin(), vis.rend());
        int res = 0;
        for(int i = 0; i < 26; i++)
        {
            res += vis[i] * ((i / 8) + 1);
        }
        return res;
    }
};