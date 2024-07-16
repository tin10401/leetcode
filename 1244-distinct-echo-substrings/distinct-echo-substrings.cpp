class Solution {
public:
    int distinctEchoSubstrings(string s) {
        int mod = 1e9 + 7;
        unordered_set<string_view> vis;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; i - j >= 0 && i + j + 1 < n; j++)
            {
                auto left = string_view(s).substr(i - j, j + 1);
                auto right = string_view(s).substr(i + 1, j + 1);
                if(left == right) vis.insert(left);
            }
        }
        return vis.size();
    }
};